#include "graph.h"

//Deletes a matrix .
void Graph::deleteMatrix(int** matrix,int n)
{
	for (int i = 0;i < n;i++)
	{
		delete matrix[i];
	}
	delete matrix;
}

//Creates a matrix
int** Graph::createMatrix(int n)
{
	int** matrix = new int*[n];
	for (int i = 0;i < n;i++)
	{
		matrix[i] = new int[n];
		for (int j = 0;j < n;j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

//Constructor
Graph::Graph()
{
	this->graph = nullptr;
	this->size = 0;
}

//Returns the amount of vertices .
int Graph::getSize()
{
	return this->size;
}

//Makes an empty Graph .
void Graph::MakeEmptyGraph(int n)
{
	if (this->size > 0)
	{
		deleteMatrix(this->graph,this->size);
	}
	this->graph = createMatrix(n);
	this->size = n;
}

//Checks if the edge is existed in the graph .
bool Graph::IsAdjacent(int u, int v)
{
	if (u >= 0 || u < this->size) 
	{
		if (v >= 0 || v < this->size)
		{
			if (this->graph[u][v] > 0) 
			{
				return true;
			}	
		}
	}
	return false;
}

//Returns vertex's Adj List (indexes).
List* Graph::GetAdjList(int u)
{
	List* adjList = nullptr;
	if (u >= 0 || u < this->size)
	{
		adjList = new List();
		for (int i = 0;i < this->size;i++)
		{
			if (IsAdjacent(u,i))
			{
				Node* node = new Node(i);
				adjList->insertToTail(node);
			}
		}
	}
	return adjList;
}

//Adds some edge to the graph , with current capacity .
void Graph::AddEdge(int u, int v, int c)
{
	if (u >= 0 || u < this->size)
	{
		if (v >= 0 || v < this->size)
		{
			this->graph[u][v] = c; 
		} 
	}
}

//Deletes some edge from the graph .
void Graph::removeEdge(int u, int v)
{
	AddEdge(u, v, 0);
}

//Returns edge's weight .
int Graph::Weight(int u, int v)
{
	if (u >= 0 || u < this->size)
	{
		if (v >= 0 || v < this->size)
		{
			return this->graph[u][v];
		}
	}
	return -1;
}

//Destructor
Graph::~Graph()
{
	if (this->size > 0)
	{
		deleteMatrix(this->graph,this->size);
	}
	this->size = 0;
	this->graph = nullptr;
}

//Returns a copy of the graph .
Graph* Graph::copyGraph(Graph* g)
{
	Graph* new_graph = new Graph();
	new_graph->MakeEmptyGraph(g->getSize());
	for (int i = 0;i < g->getSize();i++)
	{
		for (int j = 0;j < g->getSize();j++)
		{
			new_graph->AddEdge(i, j, g->Weight(i, j));
		}
	}
	return new_graph;
}

