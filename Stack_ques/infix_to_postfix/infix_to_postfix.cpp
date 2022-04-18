// infix_to_postfix
#include <iostream>
#include<stack>
#include<cassert>

int precedence(char input)
{
	//setting precendence for operators popping 
	if (input == '(') { //open brackets aren't allowed to pop anything 
		return 0;
	}
	if (input == '*' || input == '/') { //* and / are allowed to pop each other only
		return 1;
	}
	if (input == '+' || input == '-') { //+ and - are allowed to pop each other and * and / 
		return 2;
	}
	if (input == ')') { //pops everything till the opening bracket
		return 3;
	}
}

std::string infix_to_postfix(std::string input)
{
	std::string result;  //stores our final output expression string
	std::stack<int> answer; //stores our operator stack

	for (int i = 0; i < input.size(); i++) {

		if (input[i] >= '0' && input[i] <= '9') {  //adding numbers to the string
			result += (input[i]);
			continue;
		}

		if (answer.empty() || (precedence(input[i]) < precedence(answer.top()))) {  //if the stack operates under lower precedence we push directly
			answer.push(input[i]);
		}
		else { //when precedence is higher we need to pop and bring it to a lower level
			while (precedence(input[i]) >= precedence(answer.top())) {
				if (answer.top() != '(') {
					result += answer.top();  //keep appending the stack till the opening bracket to the resultant expression
				}
				answer.pop(); //we don't add brackets in our postfix expression

				if (answer.empty()) { //check to ensure the stack isn't empty from all the pops above
					break;
				}
			}
			if (input[i] != ')') {
				answer.push(input[i]);
			}
		}
	}

	//popping the last few operators from the stack to complete the expression
	while (!answer.empty()) {
		if (answer.top() == '(') { //checking for an opening bracket that couldn't find it's complement
			std::cout << "Invalid expression";
			assert(false);
		}
		result += answer.top();
		answer.pop();
	}
	return result;
}


int postfix_calculator(std::string input)
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
	std::cout << infix_to_postfix("5*(6+7)/4") << std::endl;
	std::cout << postfix_calculator(infix_to_postfix("((5+4)*6)"));
}


