/*Encrypt or decrypt a file using:
An offset cipher: In an offset cipher each character from the source file is offset with a fixed value and then written to the
target file. For example, if character read from the source file is ‘A’, then convert this into a new character by offsetting
‘A’ by a fixed value, say 128, and then writing the new character to the target file.*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include<string.h>

int main()
{
	FILE* file1 = 0;
	FILE* file2 = 0;
	char ch1;

	int offset = 4;
	if (file2 = fopen("target.txt", "w")) {
		if (file1 = fopen("finale.txt", "r")) {

			while ((ch1 = fgetc(file1)) != EOF) {

				if (ch1 != '\n') {
					fputc(ch1 + offset, file2);
				}
				else {
					fputc(ch1, file2);
				}

			}
		}
	}
	fclose(file1);
	fclose(file2);
	return 0;
}
