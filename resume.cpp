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
	for(int i = 0; i < 4; ++i){
		current->add_child();
		current = current->next();
	}

	// Add a four node variation starting at node number 4:
	current = root->next()->next()->next()->next();
	for(int i = 0; i < 4; ++i){
		current->add_child();
		current = current->next();
	}

}

