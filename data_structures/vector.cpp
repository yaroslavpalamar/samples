#include <iostream>
using namespace std;

/*
	How to create dynamic array or vector
	1. should be push_back function with pointer to link to arr(int *&arr), link to size and value in array
		inisde push_back allocate memory int* newArr with current size 
		and reassign newArr[i]=arr[i] in loop
		newArr[size] = value
		delete[] old arr
		reassign pointer arr = newAll
		increaze size++
	2. create pop_back function which crate newArr, decrease size--
		move all values from old arr to new,  delete old and reassign pointers
*/

void fillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

void showArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void push_back(int *&arr, int &size, const int value)
{
	int* newArr = new int[size+1];
	for (int i = 0; i < size; ++i) {
		newArr[i]=arr[i];
	}
	newArr[size] = value;

	delete[] arr;

	arr = newArr;
	size++;
}

void pop_back(int *&arr, int &size)
{
	// also need to implement capacity to increase vector performance!!!
	size--;
	int* newArr = new int[size+1];
	for (int i = 0; i < size; ++i) {
		newArr[i]=arr[i];
	}
	delete[] arr;
	arr = newArr;
}

int main()
{
	int size = 5;
	int *arr = new int[size];

	fillArray(arr, size);
	showArray(arr, size);
	
	push_back(arr, size, 777);
	showArray(arr, size);

	pop_back(arr, size);
	showArray(arr, size);
	

	delete [] arr;
	return 0;	
}

