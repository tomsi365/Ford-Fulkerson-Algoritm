#ifndef LIST_H
#define LIST_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "node.h"

class List 
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	List();
	void insertToTail(Node* node);
	Node* removeFromHead();
	Node* getHead();
	bool isEmpty();
	void makeEmpty();
	~List();
};

#endif // !LIST_H