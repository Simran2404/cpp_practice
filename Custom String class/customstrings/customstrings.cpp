#include "customstrings.hpp"
#include <iostream>

int string_size(const char *word) // for the length of the const char* parameters
{
	int len = 0;
	for (int i = 0; word[i] != 0; i++)
	{
		len = len + 1;
	}
	return len;
}

String::String() // default constructor
{
	array = nullptr;
	length = 0;
}

void String::print()
{
	std::cout << array << std::endl; // cout prints out character wise till a null terminating string (without a for loop)
}

// parameterized constructor
String::String(const char *word) /*constructors just allow you to automatically initialise objects so
									you don't have to call functions to initialise them yourself*/
{
	length = string_size(word);
	array = (char *)malloc(length + 1);

	for (int i = 0; i < length; i++)
	{
		array[i] = word[i];
	}
	array[length] = 0;
}

int String::size() const // for the length of the string
{
	return length;
}

// shallow copies of a pointer just copy the address of the pointer and do not allocate any memory or copy the contents being pointed to
// deep copying allocates memory for the copy and then copies the actual value, so that the copy lives in distinct memory from the source.
// copy constructors and overloaded assignment operators are written for deep copying

String::String(String const &s2) // copy constructors create new copies of already existing objects
{
	length = s2.size();
	array = (char *)malloc(s2.size() + 1);
	for (int i = 0; i < length; i++)
	{
		array[i] = s2.array[i];
	}
	array[length] = 0;
	std::cout << "copy constructor\n";
}

String &String::concatenate(const char *new_word) /*we don't need to pass the string as a parameter again because our
													function here is a method defined in the class itself*/
{
	int string_len = length;
	int new_word_len = string_size(new_word);
	int final_word_len = string_len + new_word_len;
	char *final_word = (char *)malloc((final_word_len + 1)); // assigning memory for the new concatenated word

	for (int i = 0; i < string_len; i++)
	{ // copying the original word to final word
		final_word[i] = array[i];
	}

	for (int i = 0; i < new_word_len; i++)
	{ // copying the new word to final word
		final_word[i + string_len] = new_word[i];
	}

	final_word[final_word_len] = 0;

	free(array);		// freeing the original array to avoid memory leaks
	array = final_word; // pointing the new array to our final word

	length = final_word_len;
	return *this;
}

String &String::concatenate(String &word)
{
	int word_len = word.size();
	int final_word_len = length + word_len;
	char *final_word = (char *)malloc((final_word_len + 1)); // assigning memory for the new concatenated word

	for (int i = 0; i < length; i++)
	{ // copying the original word to final word
		final_word[i] = array[i];
	}

	for (int i = 0; i < word_len; i++)
	{ // copying the new word to final word
		final_word[i + length] = word.array[i];
	}
	final_word[final_word_len] = 0;
	free(array);
	length = final_word_len; // maintaining the state of the object
	array = final_word;
	return *this;
}

String &String::to_uppercase()
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] >= 'a' && array[i] <= 'z')
		{
			array[i] = array[i] - 32;
		}
	}
	return *this;
}

String &String::to_lowercase()
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] >= 'A' && array[i] <= 'Z')
		{
			array[i] = array[i] + 32;
		}
	}
	return *this;
}

String &String::to_titlecase()
{
	array[0] = array[0] - 32;
	for (int i = 0; i < length; i++)
	{
		if (array[i] != ' ')
		{
			continue;
		}
		else
		{
			if (array[i + 1] >= 'A' && array[i + 1] <= 'Z')
			{
				continue;
			}
			else
			{
				array[i + 1] = array[i + 1] - 32;
			}
		}
	}
	return *this;
}

String &String::reverse_string()
{
	int string_len = string_size(array);
	char temp;
	int word_counter = 0; // counter to traverse the memory from the left

	for (int i = string_len - 1; i > (string_len - 1) / 2; i--)
	{ // counter to traverse the array from the right
		temp = array[word_counter];
		array[word_counter] = array[i];
		array[i] = temp;
		word_counter++;
	}
	return *this;
}

String::~String() // destructors are usually called as soon as it exits the object scope it was declared in
{
	free(array);
}

// operator overloading

String &String::operator+(String &word)
{
	return concatenate(word);
}

String &String::operator+(const char *new_word)
{
	return concatenate(new_word);
}

String &String::operator=(String &word) // assignment operator just changes the values of the existing objects
{
	if (array == word.array)
	{
		return *this;
	}
	free(array);
	length = word.size();
	array = (char *)malloc(word.size() + 1);
	for (int i = 0; i < word.size(); i++)
	{
		array[i] = word.array[i];
	}
	array[length] = 0;
	std::cout << "copy assignment operator\n";
	return *this;
}

String &String::operator=(const char *new_word)
{
	if (array == new_word)
	{
		return *this;
	}

	free(array); // no action occurs when the array which is initially set to nullptr otherwise it frees garbage values
	int word_length = string_size(new_word);
	array = (char *)malloc(word_length + 1);
	for (int i = 0; i < word_length; i++)
	{
		array[i] = new_word[i];
	}
	array[word_length] = 0;
	std::cout << "assignment operator with char*\n";
	return *this;
}

String operator+(const char *word1, String &word2)
{
	String final_word = word1;
	final_word = final_word.concatenate(word2);
	return final_word;
}

// String::String(String &&s)
// {
// 	array = s.array;
// 	s.array = nullptr;
// 	length = s.length;
// 	s.length = 0;

// 	std::cout << "Move constructor" << std::endl;
// }

// String &String::operator=(String &&s)
// {
// 	free(array);
// 	array = s.array;
// 	s.array = nullptr;
// 	length = s.length;
// 	s.length = 0;

// 	std::cout << "Move assignment" << std::endl;
// 	return *this;
// }