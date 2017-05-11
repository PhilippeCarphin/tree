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
	Node *tree = make_tree();
	DisplayVisitor dv;

	// Go through the tree and assign depth and height to each node
	AssignmentVisitor av;
	av.visit(tree);

	// Once that's done, go through the tree in a depth first search and assing
	// grid positions to each node
	GridVisitor gv;
	gv.visit(tree);

	// Show the tree's data
	dv.visit(tree);

	// Display the grid of nodes
	gv.g.show();

	return 0;
}
