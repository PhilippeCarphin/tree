class Node {
	public:
		Node(){
			number = object_counter;
			instance_counter++;
		}

		void add_child(){ children.push_back(new Node());}
		void add_child(Node *n){children.push_back(n);}
		Node *get_child(int i){ return children[i];}
		Node *next(){ return children[0];}
	
	private:
		std::vector<Node*> children;
		int number;
		static int instance_counter;
}

Node *make_tree()
{
	Node *root = new Node();

	// Mainline of 10 nodes
	Node *current = root;
	for(int i = 0; i < 10; ++i){
		current->add_child();
		current = current->next();
	}

	// Add a four node variation starting at node number 2:
	current = root->next()->next();
	current->add_child();
	current = current->child(1);
	for(int i = 0; i < 3; ++i){
		current->add_child();
		current = current->next();
	}

	// Add a four node variation starting at node number 4:
	current = root->next()->next()->next()->next();
	current->add_child();
	current = current->child(1);
	for(int i = 0; i < 3; ++i){
		current->add_child();
		current = current->next();
	}

	return root;
}


/*******************************************************************************
 * Now, we add a depth and heigh to the nodes.  I do this with an object that
 * goes through the tree.  A kind of visitor without the double dispatch.
*******************************************************************************/
class Node {
	public:
		...

		int height;
		int depth;

		void is_leaf(){return children.size() == 0;}
};

class DepthHeightVisitor : public Visitor {
	public:
		DepthHeightVisitor() :depth(0){}
		void set_height(Node *n);
		void visit(Node *n);
		int depth;
};

void DepthHeightVisitor::visit(Node *n)
{
	n->depth = this->depth;
	this->depth++;
	for(Node *c : n->children){
		visit(c);
	}
	set_height(n);
	this->depth--;

}

void DepthHeightVisitor::set_height(Node *n)
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
/*******************************************************************************
 * Now, we have the info to place the nodes on a grid:
 * And another "visitor" that has a grid, and it visits the tree in such a way
 * that the main-line gets placed first, then the variation starting at move 4,
 * The node 15 has height 3, so we we look 3+1 places to the right to find that
 * we can place all it's nodes on row 1 (the second row)
 * Then we look at the variation starting at node 2.  Node 11 has height 3, so
 * we look at j=3,4,5,6.  We find the the max_occupied_i for column 3 is 0, for
 * column 4 it is 0, for column_5, it is 1 and for column 6 it is 1, we remember
 * the highest value found and add 1.  Therefore, the whole variation goes on
 * row 2.
*******************************************************************************/
class Grid {
	public:
		int &elem(int i, int j);
		int max_occupied_i(int column);
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
			for(int j = n->j; j < n->depth + n->mainline_height + 1; ++j){
				if(max_occupied_i < g.max_occupied_i(j)){
					max_occupied_i = g.max_occupied_i(j);
				}
			}
			n->i = max_occupied_i + 1;
			if(n->number == 30)
				;//std::cout << "Max_occupied_i " << max_occupied_i << std::endl;
			g.elem(n->i, n->j) = n->number;

		}
};

