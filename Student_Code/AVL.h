#pragma once
#include "AVLInterface.h"
#include "Node.h"

class AVL: public AVLInterface
{

public:

	AVL();
	~AVL();

	NodeInterface* getRootNode();

	bool add(int data);
	bool remove(int data);
	bool found(int value);
	void clear();

	Node* IOP(Node* curr, Node* rNode);
	Node* balance(Node* node);

	Node* add_helper(Node* curr, int value);
	Node* remove_helper(Node* curr, int x);
	bool found_helper(Node* curr, int value);

	void RR(Node* a, Node* b);
	void RL(Node* a, Node* b, Node* c);
	void LL(Node* a, Node* b);
	void LR(Node* a, Node* b, Node* c);

	int size();

};

