// prefix_calculator 
#include <iostream>
#include<stack>
#include<string>
#include<cassert>

int function(std::string input)
{
	std::stack<int> result;
	int op1, op2;

	for (int i = input.size() - 1; i >= 0; i--) {

		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

			assert(result.size() >= 2);

			op1 = result.top();
			result.pop();

			op2 = result.top();
			result.pop();

			if (input[i] == '+') {
				result.push(op1 + op2);
			}
			if (input[i] == '-') {
				result.push(op1 - op2);
			}
			if (input[i] == '*') {
				result.push(op1 * op2);
			}
			if (input[i] == '/') {
				if (op2 == 0) {
					std::cout << "Division by 0";
					assert(false);
				}
				result.push(op1 / op2);
			}
		}
		else {
			result.push(input[i] - '0');
		}
	}

	if (result.size() == 1) {
		return result.top();
	}
	else {
		std::cout << "Invalid expression";
		assert(false);
	}
}

int main()
{
	std::cout << function("+5/*78-34");
}
