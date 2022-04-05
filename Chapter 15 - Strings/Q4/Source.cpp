/*To uniquely identify a book a 10-digit ISBN (International Standard
Book Number) is used. The rightmost digit is a checksum digit. This
digit is determined from the other 9 digits using the condition that
d1 + 2d2 + 3d3 + ... + 10d10 must be a multiple of 11 (where di
denotes the ith digit from the right). The checksum digit d1 can be
any value from 0 to 10: the ISBN convention is to use the value X to
denote 10. Write a program that receives a 10-digit integer,
computes the checksum, and reports whether the ISBN number is
correct or not.*/

#include<iostream>
using namespace std;

int main() {
	char s[] = "45378567X ";
	int t[25];
	int answer = 0;
	int checksum = 0;
	
	for (int i = 0; i < strlen(s); i++) {
		
		if (s[i] == 'X') {
			t[i] =10;
		}
		else {
			t[i] = s[i] - '0';
		}
	}

	int j = 2;
	for (int i = strlen(s) - 2; i >= 0; i--) {

		int final;
		final = t[i] * (j);
		answer += final;
		j++;
	}

	for (int j = 0; j < 12; j++) {

		if ((answer + j) % 11 == 0) {
			checksum = j;
		}
	}
	cout << checksum<<endl;
	cout << answer << endl;

	if ((checksum + answer) % 11 == 0) {

		cout << "The book has a valid ISBN ";
	}


}
