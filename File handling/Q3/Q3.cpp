/*Write a program to copy contents of one file to another. While
doing so replace all lowercase characters to their equivalent
uppercase characters.*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include<string.h>

int main()
{
	FILE* file = 0;
	FILE* file1 = 0;
	char str[150];
	char str1[150];
	char ch;

	if (file = fopen("hello1.txt", "a")) {
		if (file1 = fopen("hello2.txt", "r")) {
			while ((fgets(str1, 150, file1)) != 0)
				for (int i = 0; i < strlen(str1); i++) {
					ch = toupper(str1[i]);
					fputc(ch, file);
				}
		}
	}
	fclose(file);
	fclose(file1);
	return 0;
}