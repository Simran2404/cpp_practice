#include <iostream>
using namespace std;

bool func(int p[][9], int i, int j) {

	int test[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	bool res = false;

	for (int k = i; k < i + 3; k++) {
		for (int m = j; m < j + 3; m++) {
			for (int n = 0; n < 9; n++) {
				if (p[k][m] == test[n]) {
					test[n] = 0;
					break;
				}
			}
		}
	}

	for (int n = 0; n < 9; n++) {
		res |= test[n];
	}

	if (!res) {
		return true;
	}
	else {
		return false;
	}
}

bool checkrow(int p[][9]) {

	int test[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool res = false;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int n = 0; n < 9; n++) {
				if (p[i][j] == test[n]) {
					test[n] = 0;
					break;
				}
			}
		}
		for (int n = 0; n < 9; n++) {
			res |= test[n];
			test[n] = n + 1;
		}
	}


	if (!res) {
		return true;
	}
	else {
		return false;
	}
}


bool checkcol(int p[][9]) {

	int test[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool res = false;

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			for (int n = 0; n < 9; n++) {
				if (p[i][j] == test[n]) {
					test[n] = 0;
					break;
				}
			}
		}
		for (int n = 0; n < 9; n++) {
			res |= test[n];
			test[n] = n + 1;
		}
	}

	if (!res) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int p[9][9] = { {5, 3,4,6,7,8,9,1,2}, {6, 7,2,1,9,5,3,4,8}, {1,9,8,3,4,2,5,6,7}, {8,5,9,7,6,1,4,2,3}, {4, 2, 6,8,5,3,7,9,1},
		{7,1,3,9,2,4,8,5,6},{9,6,1,5,3,7,2,8,4}, {2,8,7,4,1,9,6,3,5},{3,4,5,2,8,6,1,7,9} };

	bool res = true;
	for (int x = 0; x < 9; x += 3) {
		for (int y = 0; y < 9; y += 3) {
			res &= func(p, x, y);
		}
	}

	res &= checkrow(p);
	res &= checkcol(p);
	if (res) {
		cout << "Sudoku is right!";
	}
}
