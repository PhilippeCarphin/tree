#include <iostream>
#include "grid.h"

class Node;
class Visitor {
	public:
		virtual ~Visitor() {};
		virtual void visit(Node *n) = 0;
};

/*******************************************************************************
 *
*******************************************************************************/
class DisplayVisitor : public Visitor {
	public:
		DisplayVisitor() : depth(0) { }
		~DisplayVisitor() {};
		virtual void visit(Node *n);
		int depth;
};

/*******************************************************************************
 *
*******************************************************************************/
class AssignmentVisitor : public Visitor {
	public:
		AssignmentVisitor() :depth(0) {}
		~AssignmentVisitor(){};

		void set_height(Node *n);
		void visit(Node *n);
		int depth;
};

/*******************************************************************************
 *
*******************************************************************************/
class GridVisitor : public Visitor {
	public:
		Grid<int> g;
		GridVisitor():g(-1){}
		void visit(Node *n);
		void do_node(Node *n);
};
