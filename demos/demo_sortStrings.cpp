#include <iostream>
#include <random>
#include "../src/heapsort.h"

void printArrayAsString(int arr[], int size);
void fillArray(int arr[], int size);
bool isSorted(int arr[], int size);

int main(){

	const int SIZE = 30;
	int *arr = new int[SIZE];

	fillArray(arr, SIZE);
	std::cout << "The string before sorting: ";
	printArrayAsString(arr, SIZE);

	Heapsort(arr, SIZE);
	std::cout << "The string after sorting:  ";
	printArrayAsString(arr, SIZE);

        if(isSorted(arr, SIZE)) std::cout << "The string was successfully sorted!" << std::endl;

	delete[] arr;
	return 0;
}

void printArrayAsString(int arr[], int size){
	for(int i = 0; i < size; i++){
		std::cout << (char)arr[i];
	}
	std::cout << std::endl;
}

void fillArray(int arr[], int size){

	std::mt19937 MersenneTwisterRand(time(0));
	for(int i = 0; i < size; i++){
		arr[i] = (int)('a' + MersenneTwisterRand() % 26);	
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
