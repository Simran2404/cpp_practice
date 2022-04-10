#pragma once
#include<iostream>
using namespace std;

template <typename T>
struct Vector
{
	T* array;
	int size;
	int capacity;

	Vector(); //default constructor
	void pushback(T entry);
	T popback();

	void print()
	{
		for (int i = 0; i < size; i++) {
			//cout << array[i] << endl;
			array[i].print();
		}
	}
};

template <typename T>
inline Vector<T>::Vector()
{
	capacity = 1;
	size = 0;
	array = new T[capacity * 2];  //element size * double the capacity
	capacity = 2;
}

template <typename T>
inline void Vector<T>::pushback(T entry)
{
	if (size == capacity) {
		int double_cap = capacity * 2;
		T* array2 = new T[double_cap];
		capacity = double_cap;
		for (int i = 0; i < size; i++) {
			array2[i] = array[i];
		}
		delete[] array;
		array = array2;
	}
	array[size] = entry;
	size += 1;
}

template <typename T>
inline T Vector<T>::popback()
{
	if (size == 0) {
		return 0;
	}
	return array[size--];
}







