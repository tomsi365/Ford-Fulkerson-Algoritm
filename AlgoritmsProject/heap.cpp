#include "heap.h"

//Returns node's Parent .
int Heap::Parent(int node)
{
	return (node - 1) / 2;
}

//Returns node's left descendant .
int Heap::Left(int node)
{
	return ((node * 2) + 1);
}

//Returns node's right descendant .
int Heap::Right(int node)
{
	return ((node * 2) + 2);
}

//Recursive Function
//Fixes the heap from the root -> down to leaves , 
//Keeps the rule that , the parent is bigger than his descendants .
void Heap::fixHeap(int root)
{
	int max = root;
	int left = Left(root);
	int right = Right(root);
	if (left< this->heapSize)
	{
		if (right < this->heapSize)
		{
			if (isBigger(left,max))
			{
				max = left;
			}
			if (isBigger(right, max))
			{
				max = right;
			}
		}
		else
		{
			if (isBigger(left, max))
			{
				max = left;
			}
		}
		if (max != root)
		{
			swap(root, max);
			fixHeap(max);
		}
	}
}

//Fixes the heap from the leaf -> up to root , 
//Keeps the rule that , the parent is bigger than his descendants .
void Heap::fixUp(int leaf)
{
	while (leaf != 0)
	{
		int parent = Parent(leaf);
		if (isBigger(leaf, parent))
		{
			swap(leaf, parent);
			leaf = parent;
		}
		else
		{
			break;
		}
	}
}

//Swaps x node , with y node , in the Heap .
void Heap::swap(int x, int y)
{
	int temp_data = this->data[x];
	this->data[x] = this->data[y];
	this->data[y] = temp_data;

	int temp_key = this->keys[x];
	this->keys[x] = this->keys[y];
	this->keys[y] = temp_key;

	int v1 = this->data[x];
	int v2 = this->data[y];
	this->pointers[v1] = x;
	this->pointers[v2] = y;
}

//Checks if x node priority , is bigger than y node priority , in the Heap .
bool Heap::isBigger(int x, int y)
{
	if (this->keys[x] > this->keys[y])
		return true;
	return false;

}

//Constructor
Heap::Heap(int n)
{
	this->data = new int[n];
	this->keys = new int[n];
	this->pointers = new int[n];
	this->allocated = true;
	this->maxSize = n;
	this->heapSize = 0;
}

//Constructor
Heap::Heap()
{
	this->data = nullptr;
	this->keys = nullptr;
	this->pointers = nullptr;
	this->allocated = false;
	this->maxSize = 0;
	this->heapSize = 0;
}

//Floyd's Algoritm ,
//Builds the heap at once , by Dynamic Programming .
void Heap::Build(int * data, int * keys, int n)
{
	if (this->allocated == false)
	{
		this->data = data;
		this->keys = keys;
		this->pointers = new int[n];
		this->heapSize = n;
		this->maxSize = n;
		for (int j = 0;j < n;j++)
		{
			int v = this->data[j];
			this->pointers[v] = j;
		}
		for (int i = (n / 2) - 1;i >= 0;i--)
		{
			fixHeap(i);
		}
		this->allocated = true;
	}
}

//Removes and Returns max priority data , from the heap .
int Heap::DeleteMax()
{
	if(this->heapSize>0)
	{
		int value = this->data[0];
		swap(0, this->heapSize - 1);
		this->heapSize--;
		fixHeap(0);
		return value;
	}
	return -1;
}

//Inserts data and key , to the heap .
void Heap::Insert(int data, int key)
{
	if (this->heapSize<this->maxSize)
	{
		this->data[heapSize] = data;
		this->keys[heapSize] = key;
		int v = this->data[heapSize];
		this->pointers[v] = heapSize;
		fixUp(this->heapSize);
		this->heapSize++;
	}
}

//Checks if the Heap , is empty .
bool Heap::IsEmpty()
{
	if (this->heapSize == 0 )
		return true;
	return false;
}

//Increases the key value , at the index , where is located the current data .
//Keeps the rule that , the parent is bigger than his descendants .
void Heap::IncreaseKey(int data, int key)
{
	int index = this->pointers[data];
	this->keys[index] = key;
	fixUp(index);
}

//Destructor
Heap::~Heap()
{
	if (this->allocated==true)
	{
		delete this->data;
		delete this->keys;
		delete this->pointers;
	}
	this->data = nullptr;
	this->keys = nullptr;
	this->pointers = nullptr;
	this->allocated = false;
	this->maxSize = 0;
	this->heapSize = 0;
}


