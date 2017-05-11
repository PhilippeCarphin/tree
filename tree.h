#include <string>
#include "grid.h"
#include <vector>
class Visitor;
class Node {
	public:
		static int n_instances;

		Node();
		Node(std::string);

		Node *next();

		Node *child(int n);

		virtual void accept_visitor(Visitor *v);
		bool is_leaf(){ return children.size() == 0;}
		void add_child(Node *n){ children.push_back(n);}
		void add_child(){children.push_back(new Node());}
		void add_line(int n){
			Node *current = this;
			for(int i = 0; i < n; i++){
				Node *n = new Node("L");
				current->add_child(n);
				current = n;
			}
		}
		int height;
		int depth;
		int i;
		int j;

		static Node *make_test_tree();
		void show();

		std::string id;
		int number;
		std::vector<Node*> children;
	private:

};

class Visitor {
	public:
		virtual ~Visitor() = 0;
		virtual void visit(Node *n) = 0;
};

class DisplayVisitor : public Visitor {
	public:
		DisplayVisitor();
		virtual ~DisplayVisitor();
		virtual void visit(Node *n);
		int depth;
};

class AssignmentVisitor : public Visitor {
	public:
		AssignmentVisitor()
		:depth(0), height(0)
		{}
		~AssignmentVisitor(){};

		void set_height(Node *n);
		void visit(Node *n);
		int height;
		int depth;
};

/*******************************************************************************
 * Depth first visitation of the tree allows us to set the depth and the height
 * of each node.
*******************************************************************************/
void AssignmentVisitor::visit(Node *n)
{
	n->depth = depth;
	depth++;

	for(Node *c : n->children){
		c->accept_visitor(this);
	}
	set_height(n);

	depth--;

}

void AssignmentVisitor::set_height(Node *n)
{
	if(n->is_leaf()){
		n->height = 0;
	} else {
		int max = 0;
		for(Node *c : n->children){
			if(c->height > max){
				max = c->height;
			}
		}
		n->height = max + 1;
	}
}


class GridVisitor : public Visitor {
	public:
		Grid<int> g;
		GridVisitor():g(-1){}
		void visit(Node *n)
		{
			do_node(n);
			for(Node *c : n->children){
				visit(c);
			}
		}
		void do_node(Node *n){
			n->j = n->depth;
			int max_occupied_i = -1;
			for(int j = n->j; j < n->depth + n->height + 1; ++j){
				if(max_occupied_i < g.max_occupied_i(j)){
					max_occupied_i = g.max_occupied_i(j);
				}
			}
			n->i = max_occupied_i + 1;
			if(n->number == 30)
				std::cout << "Max_occupied_i " << max_occupied_i << std::endl;
			g.elem(n->i, n->j) = n->number;

		}
};



Visitor::~Visitor(){}

DisplayVisitor::~DisplayVisitor()
{
	std::cout << __FUNCTION__ << std::endl;
}

DisplayVisitor::DisplayVisitor()
: depth(0)
{
}

void DisplayVisitor::visit(Node *n){
	for(int i = 0; i < depth; i++){
		std::cout << " ";
	}
	n->show();
	for( Node *child : n->children )
	{
		depth++;
		child->accept_visitor(this);
		depth--;
	}
}
