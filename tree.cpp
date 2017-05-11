#include <iostream>
#include "tree.h"

int Node::n_instances = 0;
Node *Node::make_test_tree()
{
	Node *root = new Node("1");
	root->add_line(10);
	Node *n = root->next()->next();
	std::cout << "Current node " << n->number << std::endl;
	n->add_line(4);
	n = n->next()->next();
	std::cout << "Current node " << n->number << std::endl;
	n->add_line(4);
	return root;
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
void Node::show(){
	// std::cout << __FUNCTION__ << std::endl
	// 	<< "  Number = " << number // 	<< "  id = " << id << std::endl;
	std::cout << number << " : Depth=" << depth << "  Height=" << height << " (i,j) = (" << i << ", " << j << ")" << std::endl;
}
Node::Node()
{
	std::cout << __FUNCTION__ << std::endl;
	id = "default";
	number = n_instances;
	n_instances++;
}

Node::Node(std::string id)
:id(id)
{
	number = n_instances;
	n_instances++;
}

Node *Node::next()
{
	return (children.size() > 0 ? children[0] : nullptr);
}
Node *Node::child(int n)
{
	if(n < 0)
		throw std::exception();
	return (n <= children.size() ? children[n] : nullptr);
}

void Node::accept_visitor(Visitor *v)
{
	v->visit(this);
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
