#include "heap.h"

int Heap::getLeftChildIndex(unsigned int index){
	return 2 * index + 1;
}

int Heap::getRightChildIndex(unsigned int index){
	return 2 * index + 2;
}

void Heap::swapNodeValue(unsigned int firstNodeIndex, unsigned int secondNodeIndex){
	unsigned int tempValue = m_pData[secondNodeIndex];
	m_pData[secondNodeIndex] = m_pData[firstNodeIndex];
	m_pData[firstNodeIndex] = tempValue;
}

bool Heap::nodeHasALeftChild(unsigned int index){
	return getLeftChildIndex(index) < m_size ? true : false;
}

bool Heap::nodeHasARightChild(unsigned int index){
	return getRightChildIndex(index) < m_size ? true : false;
}

void Heap::trySwapNodes(unsigned int currentIndex, unsigned int childIndex, bool wasSwaped){
	int childValue = m_pData[childIndex];
	if(childValue > m_pData[currentIndex]){
		swapNodeValue(childIndex, currentIndex);
		wasSwaped = true;
	}
}

Heap::Heap(int *pData, unsigned const int size) : m_pData(pData), m_size(size){

}

void Heap::heapify(){
	for (unsigned int index = m_size - 1; index >= 0; index--){
		bool wasSwaped = false;
		if(nodeHasALeftChild(index)) trySwapNodes(index, getLeftChildIndex(index), &wasSwaped);
		if(nodeHasARightChild(index)) trySwapNodes(index, getRightChildIndex(index), &wasSwaped);
		if(wasSwaped) heapify();
	}
}

void Heap::pop(){
	swapNodeValue(0, m_size - 1);
	m_size--;
}
