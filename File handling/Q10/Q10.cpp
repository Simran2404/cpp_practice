/*Write a program to carry out the following:
(a) Read a text file ‘INPUT.TXT’
(b) Print each word in reverse order
Example:
Input: INDIA IS MY COUNTRY
Output: AIDNI SI YM YRTNUOC*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;

vector<char> reverse(vector<char> word)
{
	vector<char> finalword;
	for (int j = word.size() - 1; j >= 0; j--) {
		finalword.push_back(word[j]);
	}
	return finalword;
}

int main()
{
	FILE* file2;
	FILE* file1;
	char ch1;
	vector<char> content;
	vector<char> answer;

	if (file1 = fopen("input.txt", "r")) {
		while ((ch1 = fgetc(file1)) != EOF) {
			content.push_back(ch1);
		}
		content.push_back(' ');   //adding a space at the end of the vector so we can take into count the last word  
	}

	if (file2 = fopen("final.txt", "w")) {
		vector<char> word;
		for (int j = 0; j < content.size(); j++) {
			if (content[j] != ' ' && content[j] != '\n') {
				word.push_back(content[j]);
			}
			else {
				answer = reverse(word);
				answer.push_back(0);
				fputs(answer.data(), file2);
				fputc(content[j], file2);
				/*we need to preserve the space of the newline
				itself which is why we use the content itself*/
				word.clear();
			}
		}
	}
}