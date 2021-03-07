#ifndef GRAPH_H
#define GRAPH_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "list.h"

class Graph
{
private:
	int** graph;
	int size;
public:
	static void deleteMatrix(int** matrix, int n);
	static int** createMatrix(int n);

	static Graph* copyGraph(Graph* g);

	Graph();
	int getSize();
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	List* GetAdjList(int u);
	void AddEdge(int u, int v, int c);
	void removeEdge(int u, int v);
	int Weight(int u, int v);
	~Graph();
};


#endif // !GRAPH_H
