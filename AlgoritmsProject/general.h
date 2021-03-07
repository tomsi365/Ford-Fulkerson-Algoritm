#ifndef GENERAL_H
#define GENERAL_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

class General
{
public :
	static int* copyArr(int* arr, int n);
	static Graph* getGraph(const char* address,int &s,int &t);
	static void writeError(const char* str);
};

#endif // !GENERAL_H