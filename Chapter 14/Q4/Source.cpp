/*Write a program to find if a square matrix is symmetric.*/

#include <stdio.h>
#include<iostream>
using namespace std;

int main()
{
	constexpr int x = 6, y = 6;

	int n[x][y] = { {1, 2, 3, 4, 8, 9},{ 5, 6, 7, 8, 18, 9},{ 9, 10, 11, 12, 21, 10}, {13, 14, 15, 16, 42, 18}, {8, 90, 18, 17, 12, 19}, {1,14, 2, 3, 4, 8} };
	int m[x][y] = { {1, 3, 3, 4, 8, 10},{ 5, 4, 7, 8, 18, 19},{ 9, 189, 11, 12, 18, 21}, {131, 14, 12, 125, 16, 42}, {18, 90, 14, 318, 17, 12}, {11, 2, 33, 4, 7, 28} };
	int arr[x][y];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = n[i][j] + m[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}