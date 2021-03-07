#ifndef HEAP1_H
#define HEAP1_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "graph.h"

class Heap
{
private:
	int* data;
	int* keys;
	int* pointers;

	int maxSize;
	int heapSize;
	bool allocated;

	static int Parent(int node);
	static int Left(int node);
	static int Right(int node);

	void fixHeap(int root);
	void fixUp(int leaf);
	void swap(int x, int y);
	bool isBigger(int x, int y);
	
public:
	Heap(int n);
	Heap();
	void Build(int* data, int* keys, int n);
	int DeleteMax();
	void Insert(int data, int key);
	bool IsEmpty();
	void IncreaseKey(int data,int key);
	~Heap();
};

#endif // !HEAP_H