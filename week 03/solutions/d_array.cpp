#include "d_array.h"
#include <iostream>

DArray::DArray() {
	capacity = 10;
	size = 0;
	arr = new double[capacity];
}

DArray::DArray(DArray const& da) {
	size = da.size;
	capacity = da.capacity;
	
	arr = new double[capacity];
	for (int i = 0; i < size; i++)
		arr[i] = da.arr[i];
}

DArray::~DArray() {
	delete[] arr;
}

void DArray::resize() {
	capacity *= 2;
	double* newArr = new double[capacity];
	
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	
	delete[] arr;
	arr = newArr;
}

void DArray::pushBack(double newValue) {
	if (size == capacity)
		resize();
	
	arr[size++] = newValue;
}

void DArray::popBack() {
	if (size > 0)
		size--;
}

void DArray::deleteAt(int index) {
	if (index >= 0 && index < size) {
		for (int i = index; i < size - 1; i++)
			arr[i] = arr[i + 1];
		size--;
	}
}
void DArray::setValue(int index, double newValue) {
	if (index >= 0) {
		for (int i = size; i <= index; i++)
			pushBack(0);
		
		arr[index] = newValue;
	}
}

int DArray::getSize() const {
	return size;
}

void DArray::print() const {
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}