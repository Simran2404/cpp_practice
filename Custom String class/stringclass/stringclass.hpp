#pragma once

struct String
{
	char array[50];
	int length = 0;
	int capacity = 50;
};

void string_print(String& s);

int string_size(String& s);

int string_size(const char* new_word);

int string_add(String& s, const char* new_word);

int string_concatenate(String& s, const char* new_word);

int to_uppercase(String& s);

int to_lowercase(String& s);

int to_titlecase(String& s);

int reverse_string(String& s);