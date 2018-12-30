#include <iostream>
using namespace std;

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

