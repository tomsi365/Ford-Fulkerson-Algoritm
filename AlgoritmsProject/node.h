#ifndef NODE_H
#define NODE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Node
{
private:
	int data;
	Node* next;
public:
	Node(int data);
	~Node();
	void updateData(int data);
	void connectNext(Node* next);
	int getData();
	Node* getNext();
};

#endif // !NODE_H