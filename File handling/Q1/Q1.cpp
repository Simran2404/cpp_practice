//Write a program to read a file and display its contents along with line numbers before each line.

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>

int main()
{
	FILE* file;
	char str[150];

	int num = 1;
	if (file = fopen("hello.txt", "r")) {
		while ((fgets(str, 150, file)) != 0)
			printf("%d" " " "%s", num++, str);
	}
	fclose(file);
	return 0;
}
