// Write a program to append the contents of one file at the end of another.

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>

int main()
{
	FILE* file = 0;
	FILE* file1 = 0;
	char str[150];

	if (file = fopen("hello1.txt", "a")) {
		if (file1 = fopen("hello2.txt", "r")) {
			while ((fgets(str, 150, file1)) != 0)
				fputs(str, file);
		}
	}

	fclose(file);
	fclose(file1);
	return 0;
}