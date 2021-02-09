#ifndef HEAP_H
#define HEAP_H

class Heap{
private:
	
	int *m_pData;
	unsigned int m_size;

private:

	int getLeftChildIndex(unsigned int index);
	int getRightChildIndex(unsigned int index);
	void swapNodeValue(unsigned int firstNodeIndex, unsigned int secondNodeIndex);
	bool nodeHasALeftChild(unsigned int index);
	bool nodeHasARightChild(unsigned int index);
	void trySwapNodes(unsigned int currentIndex, unsigned int childIndex, bool wasSwaped);

public:

	Heap(int *pData, unsigned int size);
	void heapify();
	void pop();
};

#endif
