#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	float arr[15] = { -6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2 };
	float mean;
	float sum = 0;

	for (int i = 0; i < 15; i++) {
		sum = sum + arr[i];
	}

	mean = sum / 15;

	float fin[15] = { };

	for (int i = 0; i < 15; i++) {
		float calc = abs(arr[i] - mean);

		for (int j = 0; j < 15; j++) {
			fin[i] = calc * calc;
		}
	}

	float sumfin = 0;

	for (int i = 0; i < 15; i++) {
		sumfin = sumfin + fin[i];
	}

	float std = sqrt(sumfin/14);
	cout << std;

}
