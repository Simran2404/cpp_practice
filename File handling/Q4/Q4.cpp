/*Write a program that merges lines alternately from two files and writes the results to new file. If one file has less
number of lines than the other, the remaining lines from the larger file should be simply copied into the target file.*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include<string.h>

int main()
{
	FILE* file = 0;
	FILE* file1 = 0;
	FILE* file2 = 0;
	char str2[150];
	char str1[150];

	if (file = fopen("finale.txt", "w")) {
		if (file1 = fopen("hello1.txt", "r")) {
			if (file2 = fopen("hello2.txt", "r")) {

				while ((fgets(str1, 150, file1) && (fgets(str2, 150, file2)) != 0)) {
					fputs(str1, file);
					fputs(str2, file);
				}

				while (fgets(str1, 150, file1) != 0) {
					fputs(str1, file);
				}

				while (fgets(str2, 150, file2) != 0) {
					fputs(str2, file);
				}
			}
		}
	}
	fclose(file);
	fclose(file1);
	fclose(file2);
	return 0;
}
