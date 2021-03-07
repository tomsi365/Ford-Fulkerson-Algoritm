#include "ford_fulkerson.h"

//FordFulkerson Algoritm - finds max flow network .
void FORD_FULKERSON::FordFulkerson(Graph* g,int s,int t, int SEARCH_ALGORITM)
{
	Graph* gf = Graph::copyGraph(g);
	Graph* f = new Graph();
	f->MakeEmptyGraph(g->getSize());
	int n = 0;
	int* p = Search(gf, s,t,n, SEARCH_ALGORITM);
	int iterations = 0;
	while (p!=nullptr) 
	{
		int cf = getCF(gf, p, s, t);
		int j = t;
		int i = s;
		while (j != i) 
		{
			f->AddEdge(p[j], j, cf + f->Weight(p[j], j));
			f->AddEdge(j, p[j], -1*f->Weight(p[j], j));
			gf->AddEdge(p[j], j, g->Weight(p[j], j) - f->Weight(p[j], j));
			gf->AddEdge(j, p[j], g->Weight(j, p[j]) - f->Weight(j, p[j]));
			j = p[j];
		}
		delete p;
		p = Search(gf, s, t,n, SEARCH_ALGORITM);
		iterations++;
	}
	printMethod(SEARCH_ALGORITM);
	printMax(f, s);
	printMinCut(gf, s);
	printIterations(iterations);
	delete f;
	delete gf;
}

//Returns path's Cf , in graph gf .
int FORD_FULKERSON::getCF(Graph* gf,int* p, int s, int t)
{
	int cf = FORD_FULKERSON::null;
	while (t != s)
	{
		int temp = gf->Weight(p[t], t);
		if (temp < cf || cf == FORD_FULKERSON::null)
		{
			cf = temp;
		}
		t = p[t];
	}
	return cf;
}

//Returns path from s to t , in the graph , by a given search algoritm .
int* FORD_FULKERSON::Search(Graph* g, int s,int t,int n, int SEARCH_ALGORITM)
{
	int* p = nullptr;
	if (SEARCH_ALGORITM == FORD_FULKERSON::bfs)
	{
		p = BFS::Bfs(g, s, n);
	}
	else 
	{
		if (SEARCH_ALGORITM == FORD_FULKERSON::dijkstra)
		{
			p = DIJKSTRA::Dijkstra(g, s, n);
		}
	}
	if (p != nullptr) 
	{
		while (p[t] != -1)
		{
			if (p[t] == s)
			{
				return p;
			}
			t = p[t];
		}
		delete p;
	}
	return nullptr;
}

//Prints Max Flow .
void FORD_FULKERSON::printMax(Graph* f, int s)
{
	int max_flow = 0;
	List* Adj = f->GetAdjList(s);
	Node* node = Adj->getHead();
	while (node != nullptr) 
	{
		max_flow += f->Weight(s, node->getData());
		node = node->getNext();
	}
	cout << "Max flow = " << max_flow << endl;
	delete Adj;
}

//Prints Min Cut groups .
void FORD_FULKERSON::printMinCut(Graph* gf, int s)
{
	int n = 0;
	int* p = BFS::Bfs(gf, s, n);
	Queue* q1 = new Queue();
	Queue* q2 = new Queue();
	cout << "Min cut: S = ";
	if (n > 0) 
	{
		q1->Enqueue(1);
	}
	for (int i = 1;i < n;i++) 
	{
		if (p[i] == -1) 
		{
			q2->Enqueue(i + 1);
		}
		else 
		{
			q1->Enqueue(i + 1);
		}
	}
	
	while (!q1->isEmpty()) 
	{
		cout << q1->Dequeue();
		if (!q1->isEmpty()) 
		{
			cout << ", ";
		}
		else 
		{
			cout << ". ";
		}
	}
	cout << "T = ";
	while (!q2->isEmpty())
	{
		cout << q2->Dequeue();
		if (!q2->isEmpty())
		{
			cout << ", ";
		}
	}
	cout << endl;
	delete q2;
	delete q1;
	delete p;
}

//Prints finding path method , used in FordFulkerson algoritm .
void FORD_FULKERSON::printMethod(int SEARCH_ALGORITM)
{
	if (SEARCH_ALGORITM == FORD_FULKERSON::bfs)
	{
		cout << "BFS Method:" << endl;
	}
	else
	{
		if (SEARCH_ALGORITM == FORD_FULKERSON::dijkstra)
		{
			cout << "Greedy Method:" << endl;
		}
	}
}

//Prints num of iterations .
void FORD_FULKERSON::printIterations(int iterations)
{
	cout << "Number of iterations = " << iterations << endl;
}




