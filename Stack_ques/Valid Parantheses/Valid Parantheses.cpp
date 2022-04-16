#include <iostream>
#include<string>
#include<stack>

bool isValid(std::string s)
{
	std::stack<char> word;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			if (word.empty()) {
				return 0;
			}

			if (word.top() == '(') {
				word.pop();
			}
			else {
				return 0;
			}
		}
		else if (s[i] == ']') {
			if (word.empty()) {
				return 0;
			}

			if (word.top() == '[') {
				word.pop();
			}
			else {
				return 0;
			}
		}
		else if (s[i] == '}') {
			if (word.empty()) {
				return 0;
			}

			if (word.top() == '{') {
				word.pop();
			}
			else {
				return 0;
			}
		}
		else {
			word.push(s[i]);
		}
	}

	if (word.empty()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	std::string s = "()";
	std::cout << isValid(s);
}







