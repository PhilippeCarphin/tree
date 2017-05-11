#include "node.h"
#include <iostream>

int Node::n_instances = 0;

/*******************************************************************************
 * Display info of a node
*******************************************************************************/
void Node::show(){
	// std::cout << __FUNCTION__ << std::endl
	// 	<< "  Number = " << number // 	<< "  id = " << id << std::endl;
	std::cout << number
		      << " : Depth=" << depth 
			  << "  Height=" << height 
			  << " (i,j) = (" << i << ", " << j 
			  << "), parent : " << (parent == nullptr ? -1 : parent->number) << std::endl;
}

/*******************************************************************************
 * Constructor
*******************************************************************************/
Node::Node()
{
	number = n_instances;
	n_instances++;
}

/*******************************************************************************
 *
*******************************************************************************/
Node::Node(Node *parent)
:parent(parent)
{
	number = n_instances;
	n_instances++;
}

/*******************************************************************************
 * Returns the first child of a node (or nullptr)
*******************************************************************************/
Node *Node::next()
{
	return (children.size() > 0 ? children[0] : nullptr);
}

/*******************************************************************************
 * Returns a selected child of a node
*******************************************************************************/
Node *Node::child(size_t n)
{
	return (n < children.size() ? children[n] : nullptr);
}
