/*Write a program to find if a square matrix is symmetric.*/

#include <stdio.h>
#include<iostream>
using namespace std;


int main()
{
	constexpr int x = 3, y = 3;

	int n[x][y] = { {1, 3, 5},{ 3,2,6} ,{5, 6, 4} };
	int temp = 1;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (n[i][j] != n[j][i]) {
				temp = 0;
				break;
			}
		}
	}

	if (temp == 1) {
		cout << "It is a symmetric matrix" << endl;
	}

	return 0;
}