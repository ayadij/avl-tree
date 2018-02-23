#pragma once
#include "NodeInterface.h"
#include <iostream>

class Node : public NodeInterface
{

public:

int data;
Node* left;
Node* right;
int height;

Node(int data, Node* left = NULL, Node* right = NULL, int height = 0){
	this->data = data;
	this->left = left;
	this->right = right;
	this->height = height;
}

int getData();

Node* getLeftChild();

Node* getRightChild();

int getHeight();

void setHeight(int value);

void updateHeight();

int getBalance();

};

