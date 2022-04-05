#include <stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int n[5][5] = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 12, 13, 15, 15, 16, 17, 18, 19, 21, 22, 25, 26, 27, 31 };
	int largest = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			if (n[i][j] > largest) {
				largest = n[i][j];
			}
	}

	cout << "The largest element in the array is: " << largest << endl;
	return 0;
}