#ifndef QUEUE_H
#define QUEUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "node.h"
#include "list.h"

class Queue
{
private:
	List* list;
public:
	Queue();
	~Queue();
	void MakeEmpty();
	bool isEmpty();
	void Enqueue(int value);
	int Dequeue();
};
#endif // !QUEUE_H