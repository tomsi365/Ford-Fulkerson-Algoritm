#include "general.h"

//Returns a copy of some array .
int* General::copyArr(int* arr, int n)
{
	int* new_arr = new int[n];
	for (int i = 0;i < n;i++) 
	{
		new_arr[i] = arr[i];
	}
	return new_arr;
}

//Returns the graph that is represented in the file .
Graph* General::getGraph(const char* address, int &s, int &t)
{
	Graph* g = nullptr;
	ifstream* in = new ifstream(address);
	char str1[1024]; // Reads n - parameter .
	in->getline(str1, 1024);
	int n = atoi(str1);
	char str2[1024]; // Reads m - parameter .
	in->getline(str2, 1024);
	int m = atoi(str2);
	char str4[1024]; // Reads s - parameter .
	in->getline(str4, 1024);
	s = atoi(str4)-1;
	char str5[1024]; // Reads t - parameter .
	in->getline(str5, 1024);
	t = atoi(str5)-1;
	g = new Graph();
	g->MakeEmptyGraph(n);
	char str3[1024]; // Reads i,j,c - parameters .
	for (int k = 0;k < m;k++) 
	{
		int x[3];
		in->getline(str3, 1024);
		char* token = strtok(str3, " ");
		int i = 0;
		while (token != nullptr) 
		{
			x[i] = atoi(token);
			token = strtok(nullptr, " ");
			i++;
		}
		if (x[2] <= 0) // Checks if there are not-positive edges .
		{
			General::writeError("invalid input");
		}
		if (x[0] == x[1]) // Checks if there are self edges .
		{
			General::writeError("invalid input");
		}
		g->AddEdge(x[0]-1, x[1]-1, x[2]);
	}
	in->close();
	return g;
}

//Prints an error message , and shuts down the program .
void General::writeError(const char* str)
{
	cout << str << endl;
	exit(1);
}

