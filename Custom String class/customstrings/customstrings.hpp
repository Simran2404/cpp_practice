#pragma once
#include <cstdlib>

int string_size(const char* word);

struct String
{
	char* array;  //initial conditions are ususally given in a default constructor 
	int size = 0;

	String(const char* word); //parameterized constructor 

	void print();

	const char* concatenate(const char* new_word);
	const char* to_uppercase();
	const char* to_lowercase();
	const char* to_titlecase();
	const char* reverse_string();

	~String(); //destructor 
};

