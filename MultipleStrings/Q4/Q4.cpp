/*Write a program to count the number of occurrences of any two
vowels in succession in a line of text. For example, in the following
sentence:
“Please read this application and give me gratuity”
such occurrences are ea, ea, ui.*/

#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	char str1[] = "Pleaease greauiose teal google pursuit";
	char sample[] = { 'a', 'e', 'i', 'o', 'u' };
	char* a = nullptr;
	int len = 1; //length of consecutive occurences
	vector<int> positions;
	vector<int> lengths;
	vector<int> consecutive;

	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(sample); j++) {
			if (str1[i] == sample[j]) {
				positions.push_back(i);
			}
		}
	}

	for (int k = 0; k < positions.size() - 1; k++) {  //the bounds are set to -1 so the check doesn't go out of bounds
		if (positions[k] + 1 == positions[k + 1]) {
			len++;
			consecutive.push_back(positions[k]);
		}
		else {
			if (len != 1) {
				lengths.push_back(len);
				consecutive.push_back(positions[k]);
			}
			len = 1;
		}
	}

	if (len != 1) {
		lengths.push_back(len);
		consecutive.push_back(positions[positions.size() - 1]);
	}

	int sum = 0;
	for (int h = 0; h < lengths.size(); h++) {
		sum += lengths[h];
	}

	int newlen = strlen(str1) - sum;
	char* result = (char*)malloc((newlen + 1) * sizeof(char));
	int position = 0;

	for (int i = 0; i < strlen(str1); i++) {
		int flag = 0;
		for (int j = 0; j < consecutive.size(); j++) {
			if (i == consecutive[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result[position] = str1[i];
			position++;
		}
	}

	result[newlen] = '\0';
	position++;

	for (int i = 0; result[i] != '\0'; i++) {
		cout << result[i];
	}
}

