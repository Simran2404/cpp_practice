#pragma once
#include <cstdlib>

int string_size(const char* word);

struct String
{
	char* array;  //initial conditions are usually given in a default constructor 
	int length;

	String(); //default constructor
	String(const char* word); //parameterized constructor
	String(String const& s); //copy constructor 
	String(String&& s);
	String& operator=(String&& s);

	void print();
	int size() const;
	String& concatenate(const char* new_word);
	String& concatenate(String& word);
	String& to_uppercase();
	String& to_lowercase();
	String& to_titlecase();
	String& reverse_string();
	~String(); //destructor 

	String& operator+(String& word);
	String& operator=(String& word);
	String& operator=(const char* new_word);
	String& operator+(const char* new_word);
};

String operator+(const char* word1, String& word2);