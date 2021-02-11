#ifndef HEAP_H
#define HEAP_H

#include <math.h>

class Heap{
private:
	
	int *m_pData;
	unsigned int m_size;

private:

	unsigned int getLeftChildIndex(unsigned int index);
	unsigned int getRightChildIndex(unsigned int index);
	unsigned int getParentIndex(unsigned int index);
	void swapNodeValue(unsigned int firstNodeIndex, unsigned int secondNodeIndex);
	bool nodeHasALeftChild(unsigned int index);
	bool nodeHasARightChild(unsigned int index);
	void checkBranchUnderLeft(unsigned int index, bool wasSwaped);
	void checkBranchUnderRight(unsigned int index, bool wasSwaped);
	void trySwapNodes(unsigned int index, unsigned int childIndex, bool wasSwaped);
	void decrementSize();

public:

	Heap(int *pData, unsigned int size);
	void heapify();
	void pop();
};

#endif
