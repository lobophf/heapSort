#include <iostream>
#include <random>
#include "../src/heapsort.h"

void printArray(char arr[], unsigned int size);
void fillArray(char arr[], unsigned int size);
bool isSorted(char arr[], unsigned int size);

int main(){

	unsigned const int SIZE = 100;
	char *arr = new char[SIZE];

	fillArray(arr, SIZE);
	std::cout << "The array before sorting:" << std::endl;
	printArray(arr, SIZE);

	Heapsort<char>(arr, SIZE);
	std::cout << std::endl << "The array after sorting:" << std::endl;
	printArray(arr, SIZE);

        if(isSorted(arr, SIZE)) std::cout << std::endl << "The array was successfully sorted!" << std::endl;

	delete[] arr;

	return 0;
}

void printArray(char arr[], unsigned int size){
	for(unsigned int i = 0; i < size; i++){
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

void fillArray(char arr[], unsigned int size){

	std::mt19937 MersenneTwisterRand(time(0));
	for(unsigned int i = 0; i < size; i++){
		arr[i] = (char)('a' + MersenneTwisterRand() % 26);	
	}
}

bool isSorted(char arr[], unsigned int size){
	for(unsigned int i = 1; i < size; i++){
		if(arr[i - 1] > arr[i]){
			return false;
		}
	}
	return true;
}
