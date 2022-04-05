/*Write a program that converts a string like "124" to an integer 124.*/

#include<iostream>
using namespace std;

int main() {
	char s[] = "45378";
	int t[25];
	int answer = 0;

	for (int i = 0; i < strlen(s); i++) {
		t[i] = s[i] - '0';
	}

	int j = 1;
	for (int n = strlen(s)-1; n >= 0; n--) {

		int final = t[n] * j;
		answer += final;
		j = j * 10;
	}
	cout << "The number is: " << answer;
}

