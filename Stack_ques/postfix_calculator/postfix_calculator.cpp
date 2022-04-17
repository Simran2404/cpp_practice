//postfix calculator 

#include<iostream>
#include<cassert>
#include<string>
#include<stack>

int function(std::string input)
{
	int op1, op2;
	std::stack<int> result;

	for (int i = 0; i < input.size(); i++) {

		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

			assert(result.size() >= 2);

			op1 = result.top();
			result.pop();
			op2 = result.top();
			result.pop();

			if (input[i] == '+') {
				result.push(op2 + op1);
			}
			if (input[i] == '-') {
				result.push(op2 - op1);
			}
			if (input[i] == '*') {
				result.push(op2 * op1);
			}
			if (input[i] == '/') {
				if (op1 == 0) {
					std::cout << "False expression";
					assert(false);
				}
				result.push(op2 / op1);
			}
		}
		else {
			result.push(input[i] - '0'); //converting characters to integers before pushing to the stack
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
	std::cout << function("78*34-/5+");
}