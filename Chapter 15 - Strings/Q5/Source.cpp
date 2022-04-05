#include<iostream>
using namespace std;

int main() {
	char s[] = "4567123456789129";
	int t[16];
	int answer = 0;
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < strlen(s); i++) {
		t[i] = s[i] - '0';
	}

	for (int i = 0; i < strlen(s); i++) {
		if (i % 2 == 0) {
			t[i] = t[i] * 2;
			if (t[i] >= 10) {
				t[i] = t[i] - 9;
			}
			sum1 = sum1 + t[i];
		}
		if (i % 2 != 0) {
			sum2 = sum2 + t[i];
		}
	}

	answer = sum1 + sum2;
	if (answer % 10 == 0) {
		cout << "This is a valid credit card number" << endl;
	}
}