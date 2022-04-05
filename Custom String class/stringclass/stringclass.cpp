#include "stringclass.hpp"
#include <iostream>

void string_print(String& s)
{
	std::cout << s.array << std::endl;
}

int string_size(String& s)
{
	int len = 0;
	for (int i = 0; s.array[i] != 0; i++) {
		len++;
	}
	return len;
}

int string_size(const char* new_word)
{
	int len = 0;
	for (int i = 0; new_word[i] != 0; i++) {
		len++;
	}
	return len;
}

int string_add(String& s, const char* new_word)
{
	int len = string_size(new_word);

	if (len <= s.capacity) {
		for (int i = 0; i < len; i++) {
			s.array[i] = new_word[i];
		}
		s.array[len] = '\0';
		return len;
	}
	else {
		for (int i = 0; i < s.capacity; i++) {
			s.array[i] = new_word[i];
		}
		s.array[s.capacity] = '\0';
		return s.capacity;
	}
}

int string_concatenate(String& s, const char* new_word)
{
	int string_len = string_size(s);
	int len = string_size(new_word);
	int position = string_len;

	if ((string_len + len) <= s.capacity) {
		s.array[string_len + len] = '\0';

		int word_counter = 0;
		for (int i = position; i < (string_len + len); i++) {
			s.array[i] = new_word[word_counter++];
		}
		return len;
	}
	else {
		int word_counter = 0;
		for (int i = position; i < s.capacity; i++) {
			s.array[i] = new_word[word_counter++];
		}
		s.array[s.capacity] = '\0';
		return s.capacity - string_len;
	}
}

int to_uppercase(String& s)
{
	for (int i = 0; s.array[i] != 0; i++) {
		if (s.array[i] >= 97 && s.array[i] <= 122) {
			s.array[i] = s.array[i] - 32;
		}
	}
	return 1;
}

int to_lowercase(String& s)
{
	for (int i = 0; s.array[i] != 0; i++) {
		if (s.array[i] >= 65 && s.array[i] <= 90) {
			s.array[i] = s.array[i] + 32;
		}
	}
	return 0;
}

int to_titlecase(String& s)
{
	s.array[0] = s.array[0] - 32;
	for (int i = 0; s.array[i] != 0; i++) {
		if (s.array[i] != ' ') {
			continue;
		}
		else {
			if (s.array[i + 1] >= 'A' && s.array[i + 1] <= 'Z') {
				continue;
			}
			else {
				s.array[i + 1] = s.array[i + 1] - 32;
			}
		}
	}
	return 0;
}

int reverse_string(String& s)
{
	int len = string_size(s);
	char temp;
	int word_counter = 0;

	for (int i = len-1; i > (len-1)/2; i--) {
		temp = s.array[word_counter];
		s.array[word_counter] = s.array[i];
		s.array[i] = temp;
		word_counter++;
	}
	return 1;
}