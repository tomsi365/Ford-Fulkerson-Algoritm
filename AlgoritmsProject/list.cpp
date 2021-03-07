#include "list.h"

//Constructor
List::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

//Destructor
List::~List()
{
	makeEmpty();
}

//Inserts Node to List's Tail .
void List::insertToTail(Node * node)
{
	if (this->size > 0)
	{
		this->tail->connectNext(node);
		this->tail = node;
	}
	else 
	{
		if (this->size == 0) 
		{
			this->head = node;
			this->tail = node;
		}
	}
	this->size++;
}

//Removes and Returns Node from List's Head .
Node* List::removeFromHead()
{
	Node* temp = this->head;
	if (this->size > 1)
	{
		this->head = this->head->getNext();
		temp->connectNext(nullptr);
	}
	else 
	{
		if (this->size == 1)
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
	}
	this->size--;
	return temp;
}

//Returns Lists's Head .
Node * List::getHead()
{
	return this->head;
}

//Checks if the List , is empty .
bool List::isEmpty()
{
	if (this->size == 0) 
		return true;
	return false;
}

//Makes an empty List .
void List::makeEmpty()
{
	while (!isEmpty())
	{
		Node* temp = removeFromHead();
		delete temp;
	}
}

