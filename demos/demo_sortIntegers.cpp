#include <iostream>
#include "../src/heapsort.h"

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(){

	const int SIZE = 15;
	
	int *arr = new int[SIZE];
	arr[0] = 4;
	arr[1] = 2;
	arr[2] = 9;
	arr[3] = 88;
	arr[4] = 1;
	arr[5] = -7;
	arr[6] = 54;
	arr[7] = 12;
	arr[8] = 13;
	arr[9] = 0;
	arr[10] = -3;
	arr[11] = 2;
	arr[12] = 4;
	arr[13] = 1;
	arr[14] = 16;

	std::cout << "array before sorting :" << std::endl;
	printArr(arr, SIZE);

	Heapsort(arr, SIZE);
	std::cout << "\narray after sorting :" << std::endl;
	printArr(arr, SIZE);

	delete[] arr;

	return 0;
}
