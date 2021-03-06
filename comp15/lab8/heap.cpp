#include "heap.h"

Heap::Heap()
{

	heap = new string[INIT_SIZE];
	heapSize = 0;
	maxCapacity = INIT_SIZE;
}


Heap::Heap(string list[], int listSize)
{

	heap = new string[listSize+1];
	maxCapacity = INIT_SIZE+1;
	//remember our implementation of a
	//heap starts at 1 not zero, so
	//we store a sentinal value at 0
	//this is not ideal as we could support
	//the null string, so it is best to
	//remember index 0 is not used
	heap[0]="";


	//copy the unsorted list over
	for(int i=0; i < listSize; i++)
	{
		heap[i+1] = list[i];
	}

	heapSize = listSize;

	//use the build heap function
	//to make it a heap
	cout << "before buildHeap" << endl;
	buildHeap();

}

//doesn't really work
//as the upHeap function
//is not implemented as it
//is nearly the same as the
//down heap funciton

void Heap::insert(string x)
{

	if(heapSize >= maxCapacity-1)
	{
		expand();
	}

	//location to insert is heapSize+1 
	//(Recall, 0th location not used)
	heap[heapSize+1] = x;
	heapSize++;

	//heapsize points to index of last element now
	//reheap or upHeap to fix
	upHeap(heapSize);

}

string Heap::removeMin()
{
	string min = heap[1];
	heap[1] = heap[heapSize];
	downHeap(1);
	heapSize--;
	return min;
}

int Heap::size()
{
	return heapSize;
}



void Heap::downHeap(int location)
{
	// if right beyond scope
	if (location * 2 + 1 > heapSize) {
	    return;
	// if left beyond scope
	} else if (location * 2 > heapSize) {
	    return;
	} else if (heap[location] > heap[location * 2] || heap[location] > heap[location * 2 + 1]) {
	    string swap = heap[location];
	    // swap for smaller value
	    if (heap[location * 2] < heap[location * 2 + 1]){
	      heap[location] = heap[location * 2];
	      heap[location * 2] = swap;
	      downHeap(location * 2);
	    } else {
	      heap[location] = heap[location * 2 + 1];
	      heap[location * 2 + 1] = swap;
	      downHeap(location * 2 + 1);
	    }  
	// don't need to downHeap any more
	} else {
	    return;
	}
}

void Heap::upHeap(int location)
{
	// not provided, as it is similar to downHeap.
	// write if you wish, but it is not mandatory for this lab.
}	

void Heap::buildHeap()
{
	// from middle to top, downheap
	for (int i=(heapSize/2);i > 0; i--){
	    downHeap(i);
	}
}

int Heap::leftChild(int index)
{
	return index*2;
}
int Heap::rightChild(int index)
{
	return index*2+1;

}
int Heap::parent(int index)
{
	return index/2;
}


//same old expand function, copying
//each element preserves the heap property
void Heap::expand()
{
	string *temp = new string[maxCapacity*2];

	for (int i = 0; i < heapSize+1; i++) {
		temp[i] = heap[i];
	}
	maxCapacity = maxCapacity*2;

	delete[] heap;
	heap = temp;
}
