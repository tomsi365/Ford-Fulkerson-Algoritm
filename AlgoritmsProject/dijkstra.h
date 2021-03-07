#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "heap.h"
#include "graph.h"
#include "list.h"
#include "node.h"
#include "general.h"

class DIJKSTRA 
{
private:
	static int const negative_infinite = -2147483647 - 1;
	static int const positive_infinite = 2147483647;
	static int const null = -1;

	static void RELAX(Graph* g, Heap* h, int* d, int* p);
	static void INIT(int s, int* d, int* p, int n);
	static int min(int a, int b);

public:
	static int* Dijkstra(Graph* g, int s, int &n);
};

#endif // DIJKSTRA_H