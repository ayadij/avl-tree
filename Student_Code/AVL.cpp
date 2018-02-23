#include "AVL.h"

int treesize = 0;
Node* root = NULL;// empty tree


AVL::AVL()
{
	root = NULL;
}

AVL::~AVL()
{
	clear();
}


/* Returns the root node for this tree. */
NodeInterface * AVL::getRootNode()
{
	return root;
}


/* Attempts to add the given int to the AVL tree
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)*/
bool AVL::add(int x)
{
	if (!(AVL::found(x))){
		root = AVL::add_helper(root, x);
		return true;
	} else {return false;}
}


/* Attempts to remove the given int from the AVL tree
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)*/
bool AVL::remove(int data)
{
	if (AVL::found(data)){
		root = AVL::remove_helper(root, data);
		return true;
	} else {return false;}
}


/* Attempts to find the value in the tree
 * @return true if found
 * @return false if unsuccessful (i.e. the int is not found in tree)*/
bool AVL::found(int value)
{
	if (root == NULL){
		return false;
	} else {
		return AVL::found_helper(root, value);
	}
}


/* Removes all nodes from the tree, resulting in an empty tree.*/
void AVL::clear()
{
	while (root != NULL){
		remove(root->data);
	}
}


Node* AVL::IOP(Node* curr, Node* parent)
{
	if (curr->right == NULL){
		int swap = parent->data;
		parent->data = curr->data;
		curr->data = swap;

		Node* savedNode = curr->left;
		delete curr;

		return balance(savedNode);
	} else {
		curr->right = AVL::IOP(curr->right, parent);
		return balance(curr);
	}
}


Node* AVL::balance(Node* a)
{
	if (a == NULL){return NULL;}

	a->updateHeight();

	if (a->getBalance() > 1) {
		Node* b = a->right;// RR or RL case
		if (b->getBalance() < 0) {
			Node* c = b->left;
			AVL::RL(a, b, c);
			return c;
		} else {
			AVL::RR(a, b);
			return b;
		}

	} else if (a->getBalance() < -1) {
		Node* b = a->left;// LL or LR case
		if (b->getBalance() > 0) {
			Node* c = b->right;
			AVL::LR(a, b, c);
			return c;
		 } else {
			AVL::LL(a, b);
			return b;
		 }
	} else {return a;}
}


Node* AVL::add_helper(Node* c, int x)
{
	if (c == NULL){return new Node(x);}

	else if (x < c->data){
		c->left = add_helper(c->left, x);
		return balance(c);
	}
	else if (x > c->data){
		c->right = add_helper(c->right, x);
		return balance(c);
	}
	return balance(c);
}


Node* AVL::remove_helper(Node* c, int x)
{
	if (x == c->data){
		if (c->left == NULL){
			 Node* temp = c->right;
			 delete c;
			 return balance(temp);
		} else {
			c->left = AVL::IOP(c->left, c);
			return balance(c);
		}
	}
	if (x < c->data){
		c->left = remove_helper(c->left, x);
		return balance(c);
	}
	if (x > c->data){
		c->right = remove_helper(c->right, x);
		return balance(c);
	}
	return balance(c);
}


bool AVL::found_helper(Node* curr, int value)
{
	if (curr == NULL){return false;}

	if (value == curr->data) {return true;}

	else if (value < curr->data){
		return found_helper(curr->left, value);
	}
	else if (value > curr->data){
		return found_helper(curr->right, value);
	}
	else {return false;}

	return false;
}


void AVL::RR(Node* a, Node* b)
{
	a->right = b->left;
	b->left = a;

	a->updateHeight();
	b->updateHeight();
}

void AVL::RL(Node* a, Node* b, Node* c)
{
	a->right = c;
	b->left = c->right;
	c->right = b;

	AVL::RR(a, c);

	a->updateHeight();
	b->updateHeight();
	c->updateHeight();
}

void AVL::LL(Node* a, Node* b)
{
	a->left = b->right;
	b->right = a;

	a->updateHeight();
	b->updateHeight();
}

void AVL::LR(Node* a, Node* b, Node* c)
{
	a->left = c;
	b->right = c->left;
	c->left = b;

	AVL::LL(a, c);

	a->updateHeight();
	b->updateHeight();
	c->updateHeight();
}


int AVL::size()
{
	return treesize;
}

