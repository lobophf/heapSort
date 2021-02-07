#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "heap.h"

class Heapsort{
private:
	int *m_pData;
	int m_size;
	Heap *m_heap = nullptr;

private:
	void sort();
	void initiateAHeap();
	void deallocateAHeap();

public:	
	Heapsort(int *pData, int size);
	~Heapsort();
};

#endif
