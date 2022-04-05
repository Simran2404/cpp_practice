/*Write a program to carry out the following operations:
- Read a text file “TRIAL.TXT” consisting of a maximum of 50 lines
of text, each line with a maximum of 80 characters.
- Count and display the number of words contained in the file.
- Display the total number of four letter words in the text file.
Assume that the end of a word may be a space, comma or a full
stop followed by one or more spaces or a newline character.*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	FILE* file1;
	char ch1;
	vector<char> content;

	if (file1 = fopen("trial.txt", "r")) {
		while ((ch1 = fgetc(file1)) != EOF) {
			content.push_back(ch1);
		}
	}


	vector<char> word;
	int countwords = 0;
	int countfour = 0;
	for (int j = 0; j < content.size(); j++) {
		if (content[j] != ' ' && content[j] != ',' && content[j] != '.') {
			word.push_back(content[j]);
		}
		else {
			countwords++;
			if (word.size() == 4) {
				countfour++;
			}
			word.clear();
		}
	}
	cout << "The number of words " << countwords << endl;
	cout << "The number of four letter words " << countfour << endl;
}