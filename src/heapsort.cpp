#include "heapsort.h"

void Heapsort::sort(){
	for(int i = 0; i < m_size - 1; i++){
		m_heap->heapify();
		m_heap->pop();	
	}
}

void Heapsort::initiateAHeap(){
	m_heap = new Heap(m_pData, m_size);
}

void Heapsort::deallocateAHeap(){
	if(m_heap){
		delete m_heap;
		m_heap = nullptr;
	}	
}

Heapsort::Heapsort(int *pData, int size) : m_pData(pData), m_size(size) {
	initiateAHeap();
	sort();
}

Heapsort::~Heapsort(){
	deallocateAHeap();
}
