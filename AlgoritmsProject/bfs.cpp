#include "bfs.h"

//Improves the path from s to current u .
void BFS::RELAX(Graph* g, Queue* q, int* d, int* p)
{
	int u = q->Dequeue();
	List* Adj = g->GetAdjList(u);
	Node* node = Adj->getHead();
	while (node != nullptr)
	{
		int v = node->getData();
		if (d[v] == BFS::positive_infinite)
		{
			d[v] = d[u] + 1;
			p[v] = u;
			q->Enqueue(v);
		}
		node = node->getNext();
	}
	delete Adj;
}

//Initialize parents array and weights array .
void BFS::INIT(int s, int* d, int* p, int n)
{
	for (int v = 0;v < n;v++)
	{
		d[v] = BFS::positive_infinite;
		p[v] = BFS::null;
	}
	d[s] = 0;
}

//BFS Algoritm - finds the shortest path tree from s (by edges amount).
int* BFS::Bfs(Graph* g, int s, int &n)
{
	Queue* q = new Queue();
	n = g->getSize();
	int* p = new int[n];
	int* d = new int[n];
	INIT(s, d, p, n);
	q->Enqueue(s);
	while (!q->isEmpty())
	{
		RELAX(g, q, d, p);
	}
	delete d;
	delete q;
	return p;
}
