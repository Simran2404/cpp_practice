/*Given a text file, write a program to create another text file deleting the words
“a”, “the”, “an” and replacing each one of them with a blank space.*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;

bool compare(vector<char> word)
{
	const char* ch1 = "a";
	const char* ch2 = "the";
	const char* ch3 = "an";
	int len = word.size();

	//instead of checking for multiple matches we check for single failures
	//initially we assume that the word input matches which is why whenever it fails we return a false
	if (strlen(ch1) == len) {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != ch1[i]) {
				return false;
			}
		}
	}

	else if (strlen(ch2) == len) {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != ch2[i]) {
				return false;
			}
		}
	}

	else if (strlen(ch3) == len) {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != ch3[i]) {
				return false;
			}
		}

	}

	//when the length doesn't match any of the conditions we assume it will be false
	else {
		return false;
	}

	return true; //default true condition because we assumed that the word matches
}

int main()
{
	FILE* file2;
	FILE* file1;
	char ch1;
	vector<char> content;
	vector<char> answer;

	if (file2 = fopen("result.txt", "w")) {
		if (file1 = fopen("final.txt", "r")) {
			while ((ch1 = fgetc(file1)) != EOF) {
				content.push_back(ch1);
			}
		}
	}

	vector<char> word;
	for (int j = 0; j < content.size(); j++) {
		if (content[j] != ' ') {
			word.push_back(content[j]);
		}
		else {
			if (compare(word) != true) {
				word.push_back(0); //adding a null at the end of the word to prevent garbage values
				fputs(word.data(), file2);
				fputs(" ", file2); //preserving spaces as per files

			}
			else {
				//fputs(" ", file2); //we don't need to add spaces again because every word leaves it's own spaces
			}
			word.clear();
		}
	}
}