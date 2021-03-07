#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "graph.h"
#include "bfs.h"
#include "dijkstra.h"


class FORD_FULKERSON
{
private:
	static int const null = -1;

	static int getCF(Graph* gf, int* p, int s, int t);
	static int* Search(Graph* g, int s, int t,int n, int SEARCH_ALGORITM);
	static void printMax(Graph* f, int s);
	static void printMinCut(Graph* gf, int s);
	static void printMethod(int SEARCH_ALGORITM);
	static void printIterations(int iterations);

public:
	static int const bfs = 1;
	static int const dijkstra = 2;

	static void FordFulkerson(Graph* g, int s, int t, int SEARCH_ALGORITM);
};

#endif // FORD_FULKERSON_H