/*Write a program to multiply any two 3 x 3 matrices.*/

#include <stdio.h>
#include<iostream>
using namespace std;

int main() {
	constexpr int rank = 3;
	int m[rank][rank] = { 1, 2, 3, 5, 6, 9, 8, 7, 4 };
	int n[rank][rank] = { 4, 8, 3, 6, 2, 9, 1, 7, 5 };
	int o[rank][rank] = { };

	int i, j, k;
	for (i = 0; i < rank; i++) {
		for (j = 0; j < rank; j++) {
			for (k = 0; k < rank; k++) {
				o[i][j] += (m[i][k] * n[k][j]);
			}
		}
		printf("\n");
	}

	//printing matrix
	for (int i = 0; i < rank; i++) {
		for (int j = 0; j < rank; j++) {
			printf("%d ", o[i][j]);
		}
		printf("\n");

	}
	return 0;
}
