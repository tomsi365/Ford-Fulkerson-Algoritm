#include "dijkstra.h"

//Improves the path from s to current u .
void DIJKSTRA::RELAX(Graph* g,Heap* h, int* d, int* p)
{
	int u = h->DeleteMax();
	List* Adj = g->GetAdjList(u);
	Node* node = Adj->getHead();
	while (node != nullptr)
	{
		int v = node->getData();
		if (d[v] < min(d[u], g->Weight(u, v)))
		{
			d[v] = min(d[u], g->Weight(u, v));
			p[v] = u;
			h->IncreaseKey(v, d[v]);
		}
		node = node->getNext();
	}
	delete Adj;
}

//Initialize parents array and weights array .
void DIJKSTRA::INIT(int s, int* d, int* p, int n)
{
	for (int v = 0;v < n;v++)
	{
		d[v] = DIJKSTRA::negative_infinite;
		p[v] = DIJKSTRA::null;
	}
	d[s] = DIJKSTRA::positive_infinite;
}

//Returns the minimal number .
int DIJKSTRA::min(int a, int b)
{
	if (a <= b)
	{
		return a;
	}
	return b;
}

//DIJKSTRA based Algoritm - finds the biggest capacity paths tree from s (by edges weights).
int* DIJKSTRA::Dijkstra(Graph* g, int s, int &n)
{
	Heap* h = new Heap();
	n = g->getSize();
	int* p = new int[n];
	int* d = new int[n];
	INIT(s, d, p, n);
	int* v = new int[n];
	for (int i = 0;i < n;i++)
	{
		v[i] = i;
	}
	h->Build(General::copyArr(v, n), General::copyArr(d, n), n);
	while (!h->IsEmpty())
	{
		RELAX(g,h, d, p);
	}
	delete v;
	delete d;
	delete h;
	return p;
}
