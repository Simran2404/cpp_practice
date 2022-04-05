/*Write a program to delete all vowels from a sentence. Assume that
the sentence is not more than 80 characters long.*/

#include<string.h>
#include <iostream>
using namespace std;

int check(char a, char* vowels) {
	for (int j = 0; j < 5; j++) {
		if (vowels[j] == a) {
			return true;
		}
	}
	return false;
}

int main()
{
	int num = 10;
	int count = 0;
	char arr[] = "abcdefghi";

	char* a = (char*)malloc((num + 1) * sizeof(char));
	char vowels[] = { 'a', 'e', 'i', 'o' ,'u' };

	for (int i = 0; i < num; i++) {
		a[i] = arr[i];
	}

	for (int i = 0; i < num; i++) {
		if (check(a[i], vowels) == true) {
			count++;
		}
	}

	int counter = 0;
	char* res = (char*)malloc((num - count + 1) * sizeof(char));

	for (int i = 0; i < num; i++) {
		if (check(a[i], vowels) == true) {
			continue;
		}
		else {
			res[counter] = arr[i];
			counter++;
		}
	}

	res[counter] = '\0';
	for (int k = 0; k < (num - count + 1); k++) {
		cout << res[k];
	}

	free(res);
	free(a);
}
