#include "vector_class.hpp"
#include "customstrings.hpp"
#include <iostream>
#include <string>
#include<cassert>
#include<stack>

int main()
{
	//string reverse
	std::string str = "simran";
	std::stack<char> word;
	for (int i = 0; i < str.size(); i++) {
		word.push(str[i]);
	}

	while (!word.empty()) {
		std::cout << word.top();
		word.pop();
	}
}

