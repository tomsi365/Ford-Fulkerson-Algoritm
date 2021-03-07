#include "node.h"

//Constructor
Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

//Destructor
Node::~Node()
{
	this->data = 0;
	this->next = nullptr;
}

//Updates node's data .
void Node::updateData(int data)
{
	this->data = data;
}

//Connects node to other node .
void Node::connectNext(Node * next)
{
	this->next = next;
}

//Returns node's data .
int Node::getData()
{
	return this->data;
}

//Returns node's next node .
Node * Node::getNext()
{
	return this->next;
}
