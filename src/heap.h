#ifndef HEAP_H
#define HEAP_H

template<class T>
class Heap{
private:
	T *m_pData;
	unsigned int m_size;

private:

	int getLeftChildIndex(unsigned int index){
		return 2 * index + 1;
	}
	
	int getRightChildIndex(unsigned int index){
		return 2 * index + 2;
	}
	
	void swapNodeValue(unsigned int firstNodeIndex, unsigned int secondNodeIndex){
		int tempValue = m_pData[secondNodeIndex];
		m_pData[secondNodeIndex] = m_pData[firstNodeIndex];
		m_pData[firstNodeIndex] = tempValue;
	}
	
	bool nodeHasALeftChild(unsigned int index){
		return getLeftChildIndex(index) < m_size ? true : false;
	}
	
	bool nodeHasARightChild(unsigned int index){
		return getRightChildIndex(index) < m_size ? true : false;
	}
	
	void trySwapNodes(unsigned int currentIndex, unsigned int childIndex, bool wasSwaped){
		int childValue = m_pData[childIndex];
		if(childValue > m_pData[currentIndex]){
			swapNodeValue(childIndex, currentIndex);
			wasSwaped = true;
		}
	}

public:
	
	Heap(T *pData, unsigned int size) : m_pData(pData), m_size(size){
	
	}
	
	void heapify(){
		for (unsigned int index = m_size - 1; index + 1 > 0; index--){
			bool wasSwaped = false;
			if(nodeHasALeftChild(index)) trySwapNodes(index, getLeftChildIndex(index), &wasSwaped);
			if(nodeHasARightChild(index)) trySwapNodes(index, getRightChildIndex(index), &wasSwaped);
			if(wasSwaped) heapify();
		}
	}
	
	void pop(){
		swapNodeValue(0, m_size - 1);
		m_size--;
	}
};

#endif
