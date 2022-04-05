/*Write a program that extracts part of the given string from the
specified position.For example, if the sting is "Working with strings
is fun", then if from position 4, 4 characters are to be extracted
then the program should return string as "king".If the number of
characters to be extracted is 0 then the program should extract
entire string from the specified position.*/

#include <iostream>
using namespace std;

char* func(int num, int extract, char arr[]) {
	//char* a = (char*)malloc((num+1) * sizeof(char));
	char a[num + 1];

	for (int i = extract; i < (extract + num); i++) {
		a[i - extract] = arr[i-1];
	}
	a[num] ='\0';
	return a;
}

int main()
{
	int num = 4;
	int extract = 4;
	char arr[] = "Working with strings is fun";
	char* res = func(num, extract, arr);
	for (int i = 0; i < num; i++) {
		cout << res[i];
	}
	free(res);
}
