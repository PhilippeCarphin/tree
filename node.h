#include <string>
#include "grid.h"
#include <vector>
class Visitor;
class Node {
	public:
		static int n_instances;

		Node();
		Node(Node *parent);
		Node(std::string);

		Node *next();

		Node *child(int n);

		bool is_leaf(){ return children.size() == 0;}
		void add_child(Node *n){ children.push_back(n);n->parent = this;}
		void add_child(){children.push_back(new Node(this));}
		void add_line(int n){
			Node *current = this;
			for(int i = 0; i < n; i++){
				Node *n = new Node("L");
				current->add_child(n);
				current = n;
			}
		}
		Node *parent = nullptr;
		int height;
		int mainline_height;
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
