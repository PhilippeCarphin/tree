#include "node.h"
#include "visitor.h"

/*******************************************************************************
 * Depth first visitation of the tree allows us to set the depth and the height
 * of each node.
*******************************************************************************/
void AssignmentVisitor::visit(Node *n)
{
	n->depth = this->depth;
	this->depth++;
	for(Node *c : n->children){
		visit(c);
	}
	set_height(n);
	this->depth--;

}

/*******************************************************************************
 *
*******************************************************************************/
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
		n->mainline_height = n->next()->mainline_height + 1;
		n->height = max + 1;
	}
}


/*******************************************************************************
 *
*******************************************************************************/

void GridVisitor::visit(Node *n)
{
	do_node(n);
	for(Node *c : n->children){
		visit(c);
	}
}
void GridVisitor::do_node(Node *n){
	n->j = n->depth;
	int max_occupied_i = -1;
	for(int j = n->j; j < n->depth + n->height + 1; ++j){
		if(max_occupied_i < g.max_occupied_i(j)){
			max_occupied_i = g.max_occupied_i(j);
		}
	}
	n->i = std::max(max_occupied_i + 1,(n->parent != nullptr ? n->parent->i : 0));
	g.elem(n->i, n->j) = n->number;
}

Visitor::~Visitor(){}

DisplayVisitor::~DisplayVisitor()
{
	std::cout << __FUNCTION__ << std::endl;
}

DisplayVisitor::DisplayVisitor()
: depth(0)
{
}

/*******************************************************************************
 *
*******************************************************************************/
void DisplayVisitor::visit(Node *n){
	for(int i = 0; i < depth; i++){
		std::cout << " ";
	}
	n->show();
	for( Node *child : n->children )
	{
		depth++;
		visit(child);
		depth--;
	}
}
