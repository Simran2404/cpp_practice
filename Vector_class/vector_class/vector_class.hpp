#pragma once
#include<iostream>
#include <cassert>
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
	void insert(int index, T key);
	void remove(int index);

	void print()
	{
		for (int i = 0; i < size; i++) {
			cout << array[i] << endl;
			//array[i].print();
		}
	}

	T& operator[](int index);
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

template<typename T>
inline T& Vector<T>::operator[](int index)  //you can't have functions vary on the basis of just return types
{
	if (index >= size || index < 0) {
		std::cout << "Invalid Index\n";;
		assert(false);
	}
	return array[index];
}

template <typename T>
inline void Vector<T>::insert(int index, T key)
{
	assert(!(index > size));
	assert(!(index < 0));

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

	assert(size < capacity);

	for (int i = size; i >= index; i--) {
		array[i + 1] = array[i];
	}
	array[index] = key;

	if (index == size) {  //pushback case
		array[index] = key;
	}
	size += 1;
}

template <typename T>
inline void Vector<T>::remove(int index)
{
	assert(!(index >= size) && (!(index < 0)));

	for (int i = index; i < size; i++) {
		array[i] = array[i + 1];
	}
	size -= 1;
}


