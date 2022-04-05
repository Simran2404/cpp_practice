#include "customstrings.hpp"
#include<iostream>

int string_size(const char* word)
{
	int len = 0;
	for (int i = 0; word[i] != 0; i++) {
		len = len + 1;
	}
	return len;
}

String::String(const char* word)
{
	size = string_size(word);  //
	array = (char*)malloc(size + 1);

	for (int i = 0; i < size; i++) {
		array[i] = word[i];
	}
	array[size] = 0;
}

void String::print()
{
	std::cout << array << std::endl; //you can directly give character pointers to cout if you have a null terminating string 
}

const char* String::concatenate(const char* new_word) //we don't need to pass the string as a parameter again because our function here is a method defined int the class itself
{
	int string_len = size;
	int new_word_len = string_size(new_word);
	int final_word_len = string_len + new_word_len;
	char* final_word = (char*)malloc((final_word_len + 1)); //assigning memory for the new concatenated word

	for (int i = 0; i < string_len; i++) {  //copying the original word to final word
		final_word[i] = array[i];
	}

	for (int i = 0; i < new_word_len; i++) {  //copying the new word to final word
		final_word[i + string_len] = new_word[i];
	}

	final_word[final_word_len] = 0;

	free(array); //freeing the original array to avoid memory leaks
	array = final_word; //pointing the new array to our final word

	size = final_word_len;
	return final_word;
}

const char* String::to_uppercase()
{
	for (int i = 0; i < size; i++) {
		if (array[i] >= 'a' && array[i] <= 'z') {
			array[i] = array[i] - 32;
		}
	}
	return array;
}

const char* String::to_lowercase()
{
	for (int i = 0; i < size; i++) {
		if (array[i] >= 'A' && array[i] <= 'Z') {
			array[i] = array[i] + 32;
		}
	}
	return array;
}

const char* String::to_titlecase()
{
	array[0] = array[0] - 32;
	for (int i = 0; i < size; i++) {

		if (array[i] != ' ') {
			continue;
		}
		else {
			if (array[i + 1] >= 'A' && array[i + 1] <= 'Z') {
				continue;
			}
			else {
				array[i + 1] = array[i + 1] - 32;
			}
		}
	}
	return array;
}

const char* String::reverse_string()
{
	int string_len = string_size(array);
	char temp;
	int word_counter = 0;  //counter to traverse the memory from the left

	for (int i = string_len - 1; i > (string_len - 1) / 2; i--) {  //counter to traverse the array from the right
		temp = array[word_counter];
		array[word_counter] = array[i];
		array[i] = temp;
		word_counter++;
	}
	return array;
}

String::~String()
{
	free(array);
}
