#include <stdio.h>
#include<iostream>
using namespace std;

int main()
{
	constexpr int x = 5, y = 5;

	int n[x][y] = { {1, 2, 3, 4, 8},{ 5, 6, 7, 8, 18},{ 9, 10, 11, 12, 21}, {13, 14, 15, 16, 42}, {8, 90, 18, 17, 12} };
	int temp = 0;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << n[j][i] << " ";
		}
		cout << endl;
	}
}