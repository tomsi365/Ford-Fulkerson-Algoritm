#ifndef BFS_H
#define BFS_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "queue.h"
#include "graph.h"
#include "list.h"
#include "node.h"


class BFS
{
private :
	static int const positive_infinite = 2147483647;
	static int const null = -1;

	static void RELAX(Graph* g, Queue* q, int* d, int* p);
	static void INIT(int s, int* d, int* p, int n);

public :
	static int* Bfs(Graph* g, int s, int &n);

};

#endif // BFS_H