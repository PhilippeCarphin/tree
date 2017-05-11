#include <iostream>
#include "node.h"
#include "visitor.h"

Node *make_tree()
{
	Node *root = new Node();

	// Mainline of 10 nodes
	Node *current = root;
	for(int i = 0; i < 8; ++i){
		current->add_child();
		current = current->next();
	}

	// Add a four node variation starting at node number 2:
	current = root->next()->next();
	current->add_child();
	current->add_child();
	current = current->child(1);
	for(int i = 0; i < 3; ++i){
		current->add_child();
		current = current->next();
	}

	// Add a four node variation starting at node number 4:
	current = root->next()->next()->next()->next();
	current->add_child();
	current->add_child();
	current = current->child(1);
	for(int i = 0; i < 3; ++i){
		current->add_child();
		current = current->next();
	}

	return root;

}

int main()
{
	std::cout << "DONE" << std::endl;
	Node *tree = make_tree();
	AssignmentVisitor av;
	av.visit(tree);
	DisplayVisitor dv;
	// dv.visit(tree);
	GridVisitor gv;
	gv.visit(tree);
	dv.visit(tree);
	gv.g.show();

	return 0;
}
