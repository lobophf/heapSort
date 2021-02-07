#ifndef HEAP_H
#define HEAP_H

class Heap{
private:
	
	int *m_pData;
	int m_size;

private:

	int getLeftChildIndex(int index);
	int getRightChildIndex(int index);
	void swapNodeValue(int firstNodeIndex, int secondNodeIndex);
	bool nodeHasALeftChild(int index);
	bool nodeHasARightChild(int index);
	void trySwapNodes(int currentIndex, int childIndex, bool wasSwaped);

public:

	Heap(int *pData, int size);
	void heapify();
	void pop();
};

#endif
