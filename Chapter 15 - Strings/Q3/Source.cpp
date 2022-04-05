/*Write a program that generates and prints the Fibonacci words of
order 0 through 5. If f(0) = "a", f(1) = "b", f(2) = "ba", f(3) = "bab",
f(4) = "babba", etc. */

#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char x1[10] = "a";
	char x2[10] = "b";
	char x3[10];

	cout << x1 << " " << x2 << " ";

	for (int i = 2; i <= 5; i++) {
		strcpy_s(x3, x2);
		strcat_s(x2, x1);
		cout << x2 << " ";

		strcpy_s(x1, x3);
	}
}

