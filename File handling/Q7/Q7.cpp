/*Encrypt or decrypt using: Substitution cipher: In this each character read from the source file is substituted
by a corresponding predetermined character and this character is written to the target file.
For example, if character ‘A’ is read from the source file, and if we have decided that every ‘A’ is to be
substituted by ‘!’, then a ‘!’ would be written to the target file in place of every ‘A’. Similarly, every ‘B’
would be substituted by ‘5’ and so on. */

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE* file1 = 0;
	FILE* file2 = 0;
	char ch1;
	const char* str = "qwertyuiopasdfghjklzxcvbnm";

	if (file2 = fopen("target.txt", "w")) {
		if (file1 = fopen("finale.txt", "r")) {
			while ((ch1 = fgetc(file1)) != EOF) {

				if (ch1 == ' ' || ch1 == '\n') {
					fputc(ch1, file2);
				}
				else {
					fputc(str[ch1 - 97], file2);
				}
			}
		}
	}

	/*
	const char* str = "qwertyuiopasdfghjklzxcvbnm";
	const char* alpha = "abcdefghijklmnopqrstuvwxyz";
	int pos = 0;

	if (file2 = fopen("target.txt", "w")) {
		if (file1 = fopen("finale.txt", "r")) {

			while ((ch1 = fgetc(file1)) != EOF) {

				if (ch1 == ' ' || ch1 == '\n') {
					fputc(ch1, file2);
				}
				else {
					for (int i = 0; i < strlen(alpha); i++) {
						if (alpha[i] == ch1) {
							pos = i;
							fputc(str[pos], file2);
						}
					}
				}
			}
		}
	}*/

	fclose(file1);
	fclose(file2);
	return 0;
}
