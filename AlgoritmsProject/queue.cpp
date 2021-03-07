#include "queue.h"

//Constructor
Queue::Queue()
{
	this->list = new List();
}

//Destructor
Queue::~Queue()
{
	delete this->list;
	this->list = nullptr;
}

//Makes an empty Queue .
void Queue::MakeEmpty()
{
	this->list->makeEmpty();
}

//Checks if the Queue , is empty .
bool Queue::isEmpty()
{
	return this->list->isEmpty();
}

//Inserts value to the Queue .
void Queue::Enqueue(int value)
{
	Node* node = new Node(value);
	this->list->insertToTail(node);
}

//Romoves and Returns value from the Queue .
int Queue::Dequeue()
{
	int temp = -1;
	if (!isEmpty()) 
	{
		Node* node = this->list->removeFromHead();
		temp = node->getData();
		delete node;
	}
	return temp;
}

