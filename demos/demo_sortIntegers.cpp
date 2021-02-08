#include <iostream>
#include <random>
#include "../src/heapsort.h"

void printArray(int arr[], int size);
void fillArray(int arr[], int size);
bool isSorted(int arr[], int size);

int main(){

	const int SIZE = 10;
	int *arr = new int[SIZE];

	fillArray(arr, SIZE);
	std::cout << "The array before sorting:" << std::endl;
	printArray(arr, SIZE);

	Heapsort(arr, SIZE);
	std::cout << std::endl << "The array after sorting:" << std::endl;
	printArray(arr, SIZE);

        if(isSorted(arr, SIZE)) std::cout << std::endl << "The array was successfully sorted!" << std::endl;

	delete[] arr;

	return 0;
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void fillArray(int arr[], int size){

	std::mt19937 MersenneTwisterRand(time(0));
	for(int i = 0; i < size; i++){
		arr[i] = MersenneTwisterRand();	
	}
}

bool isSorted(int arr[], int size){
	for(int i = 1; i < size; i++){
		if(arr[i - 1] > arr[i]){
			return false;
		}
	}
	return true;
}
