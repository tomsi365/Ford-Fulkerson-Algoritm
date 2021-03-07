#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"
#include "ford_fulkerson.h"
#include <iostream>
using namespace std;

int main();
void run(const char* str);

//main
int main()
{
	run("input1.txt");
	run("input2.txt");
	run("input3.txt");
	run("input4.txt");
	run("input5.txt");
	//system("pause");
}

void run(const char* str) {
	int s = 0, t = 0;
	Graph* g;
	g = General::getGraph(str, s, t);
	FORD_FULKERSON::FordFulkerson(g, s, t, FORD_FULKERSON::bfs);
	FORD_FULKERSON::FordFulkerson(g, s, t, FORD_FULKERSON::dijkstra);
	delete g;
}




