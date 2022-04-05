#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	char str1[] = "Malab Sankar Barik";
	char* a = nullptr;
	int spacescount = 0;
	int pos = 0; //to keep tabs on the next word to be extracted
	int len = 0; //length of the words that are being extracted
	int newlen = 0;
	vector<char*> result;


	for (int p = 0; p < strlen(str1); p++) {
		if (str1[p] == ' ') {
			spacescount++;
		}
	}

	for (int i = 0; i < strlen(str1); i = pos) {
		for (int j = i; j < strlen(str1); j++) {
			if (str1[j] != ' ') {
				len++;
			}
			else {
				break;
			}
		}

		newlen += len;
		char* a = (char*)malloc((len + 1) * sizeof(char)); //allocating memory for all the words extracted

		for (int k = 0; k < len; k++) {
			a[k] = str1[pos];
			pos++;
		}

		a[len] = '\0';
		pos += 1; //incrementing pos to accomodate the null at the end
		len = 0; //resetting len for the next iteration 

		result.push_back(a);
	}

	int position = 0;
	char* arr = (char*)malloc((newlen + 1 + spacescount) * sizeof(char));

	int res = result.size();

	for (int p = 0; p < (res - 1); p++) {
		arr[position++] = result[p][0];
		arr[position++] = '.';
	}


	for (int g = 0; g < strlen(result[res - 1]); g++) {
		arr[position++] = result[res - 1][g];
	}

	arr[position] = '\0';

	for (int p = 0; arr[p] != 0; p++) {
		cout << arr[p];
	}
}
