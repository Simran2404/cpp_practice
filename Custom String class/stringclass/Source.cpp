#include "stringclass.hpp"
#include <iostream>

int main()
{
	String s;
	std::cout << string_size("simran") << std::endl;

	const char* new_word = "abc abc abc";
	std::cout << string_add(s, new_word) << std::endl;
	string_print(s);

	std::cout << reverse_string(s) << std::endl;
	string_print(s);

	std::cout << string_concatenate(s, "hgfhgjfjhgfsdndknvlsdmclasmx") << std::endl;
	string_print(s);

	std::cout << to_titlecase(s) << std::endl;
	string_print(s);

	std::cout << to_lowercase(s) << std::endl;
	string_print(s);

	std::cout << to_uppercase(s) << std::endl;
	string_print(s);
}