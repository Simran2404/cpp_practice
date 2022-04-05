/*Write a program that receives an integer (less than or equal to nine
digits in length) and prints out the number in words. For example, if
the number input is 12342, then the output should be Twelve
Thousand Three Hundred Forty Two.*/

#include <iostream>
#include<vector>
using namespace std;

void func(vector<const char*>* words, int extract, const char* ones[], const char* twos[], const char* tens[])
{
	while (extract / 10 != 0) {
		if (extract / 10 == 1) {
			(*words).push_back(twos[extract % 10 - 1]);
		}
		else {
			(*words).push_back(ones[extract % 10]);
			(*words).push_back(tens[(extract / 10) - 1]);
		}
		extract = extract / 10;
	}
}

int main()
{
	vector<const char*> words;
	const char* ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	const char* twos[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char* tens[] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const char* big[] = { "ten", "hundred", "thousand", "million" };

	int num = 123456789;
	int number = num;
	int count = 1;
	int extract = 0;

	while (number / 10 != 0) { //for the length of the number
		count++;
		number = number / 10;
	}

	//89
	if (num / 10 != 0) {
		extract = num % 100;
		//std::cout << num << std::endl;
		func(&words, extract, ones, twos, tens);
	}

	/*for (auto word : words) {
		cout << word << endl;
	}*/

	num = num / 100;

	//7
	if (num / 10 != 0) {
		extract = num % 10;
		words.push_back(big[1]);
		words.push_back(ones[extract]);
	}


	num = num / 10;

	//56
	if (num / 10 != 0) {
		extract = num % 100;
		words.push_back(big[2]);
		//std::cout << num << std::endl;
		func(&words, extract, ones, twos, tens);
	}

	num = num / 100;

	//4
	if (num / 10 != 0) {
		extract = num % 10;
		words.push_back(big[1]);
		words.push_back(ones[extract]);
	}

	num = num / 10;

	//23
	if (num / 10 != 0) {
		extract = num % 100;
		words.push_back(big[3]);
		//std::cout << num << std::endl;
		func(&words, extract, ones, twos, tens);
	}

	num = num / 100;

	//1
	if (num) {
		extract = num % 10;
		words.push_back(big[1]);
		words.push_back(ones[extract]);
	}
	for (auto word : words) {
		cout << word << endl;
	}

	for (int i = words.size() - 1; i >= 0; i--) {
		cout << words[i] << " ";
	}
}

