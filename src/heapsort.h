#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include "heap.h"

template<class T>
class Heapsort{
private:
	T *m_pData;
	unsigned const int m_SIZE;
	Heap<T> *m_heap = nullptr;

private:

	void sort(){
		for(unsigned int i = 0; i < m_SIZE - 1; i++){
			m_heap->heapify();
			m_heap->pop();	
		}
	}
	
	void initiateAHeap(){
		m_heap = new Heap<T>(m_pData, m_SIZE);
	}
	
	void deallocateAHeap(){
		if(m_heap){
			delete m_heap;
			m_heap = nullptr;
		}	
	}

public:	
	Heapsort(T *pData, unsigned int size) : m_pData(pData), m_SIZE(size) {
		initiateAHeap();
		sort();
	}

	~Heapsort(){
		deallocateAHeap();
	}
};

#endif
