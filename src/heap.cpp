#include "heap.h"

unsigned int Heap::getLeftChildIndex(unsigned int index){
	return 2 * index + 1;
}

unsigned int Heap::getRightChildIndex(unsigned int index){
	return 2 * index + 2;
}

void Heap::swapNodeValue(unsigned int firstNodeIndex, unsigned int secondNodeIndex){
	int tempValue = m_pData[secondNodeIndex];
	m_pData[secondNodeIndex] = m_pData[firstNodeIndex];
	m_pData[firstNodeIndex] = tempValue;
}

bool Heap::nodeHasALeftChild(unsigned int index){
	return getLeftChildIndex(index) < m_size ? true : false;
}

bool Heap::nodeHasARightChild(unsigned int index){
	return getRightChildIndex(index) < m_size ? true : false;
}

void Heap::trySwapNodes(unsigned int index, unsigned int childIndex, bool wasSwaped){
	wasSwaped = false;
	int childValue = m_pData[childIndex];
	if(childValue > m_pData[index]){
		swapNodeValue(childIndex, index);
		wasSwaped = true;
	}
}

Heap::Heap(int *pData, unsigned int size) : m_pData(pData), m_size(size){

}

void Heap::checkBranchUnderLeft(unsigned int index, bool wasSwaped){
	if(nodeHasALeftChild(index)) trySwapNodes(index, getLeftChildIndex(index), &wasSwaped);
}

void Heap::checkBranchUnderRight(unsigned int index, bool wasSwaped){
	if(nodeHasARightChild(index)) trySwapNodes(index, getRightChildIndex(index), &wasSwaped);
}

void Heap::heapify(){
	for (unsigned int index = m_size - 1; index + 1 > 0; index--){
		bool wasSwaped = false;
		checkBranchUnderLeft(index, &wasSwaped);
		checkBranchUnderRight(index, &wasSwaped);
		if(wasSwaped) heapify();
	}
}

void Heap::decrementSize(){
	m_size--;
}

void Heap::pop(){
	swapNodeValue(0, m_size - 1);
	decrementSize();
}
