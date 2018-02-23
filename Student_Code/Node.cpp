#include "Node.h"


/* Returns the data that is stored in this node.*/
int Node::getData()
{
	return data;
}


/* Returns the left child of this node or null if it doesn't have one. */
Node* Node::getLeftChild()
{
	return left;
}


/* Returns the right child of this node or null if it doesn't have one. */
Node* Node::getRightChild()
{
	return right;
}


int Node::getHeight()
{
	return height;

}


void Node::setHeight(int value){
	height = value;
}


void Node::updateHeight() {
	int LH;
	if (left == NULL){
		LH = -1;
	} else {LH = left->height;}

	int RH;
	if (right == NULL){
		RH = -1;
	} else {RH = right->height;}

	height = max(LH,RH) + 1;
}


int Node::getBalance() {
	int LH = (left == NULL) ? -1 : left->height;
	int RH = (right == NULL) ? -1 : right->height;
	int balance = RH - LH;
	return balance;
}


