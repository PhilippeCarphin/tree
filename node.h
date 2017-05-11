#include <string>
#include <vector>
class Visitor;
class Node {
	public:
		static int n_instances;

		Node();
		Node(Node *parent);
		Node *next();
		Node *child(size_t n);
		bool is_leaf(){ return children.size() == 0;}
		void add_child(Node *n){ children.push_back(n);n->parent = this;}
		void add_child(){children.push_back(new Node(this));}
		Node *parent = nullptr;
		int height;
		int mainline_height;
		int depth;
		int i;
		int j;

		static Node *make_test_tree();
		void show();

		int number;
		std::vector<Node*> children;
	private:

};
