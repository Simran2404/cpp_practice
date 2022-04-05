/*Given an array p[5], write a function to shift it circularly left by two
positions.Thus, if p[0] = 15, p[1] = 30, p[2] = 28, p[3] = 19 and p[4] = 61
then after the shift p[0] = 28, p[1] = 19, p[2] = 61, p[3] = 15 and p[4] = 30.
Call this function for a(4 x 5) matrix and get its rows left shifted.*/

#include <iostream>
#include<stdio.h>
using namespace std;

int func(int p[5], int n)
{
	int m[5] = { };
	for (int j = 0; j < n; j++) {
		m[j + (5 - n)] = p[j];
	}

	for (int j = n; j < 5; j++) {
		m[j - n] = p[j];
	}

	for (int i = 0; i < 5; i++) {
		cout << m[i] << " ";
	}
	return 0;
}

int main() {
	int p[4][5] = { {1, 2, 3, 4, 5}, {4, 5, 6 ,7, 8}, {10, 11, 12, 14, 15}, {56, 35, 23, 21, 13} };

	int n = 2;

	for (int i = 0; i < 4; i++) {
			func(p[i], n);
			cout << " " << endl;
		}
	
}