#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	float p[6][4] = { {1, 137.4, 80.9, 0.78}, {2, 155.2, 92.62, 0.89}, {3, 149.3, 97.93, 1.35},
		{4, 160.0, 100.25, 9.00 }, { 5, 155.6, 68.95, 1.25 }, { 6, 149.7, 120.0, 1.75 } };

	float ab;
	float fin[6];
	float comp, ans;

	for (int i = 0; i < 6; i++) {
		ab = p[i][1] * p[i][2];
		comp = sin(p[i][3]);
		cout << ab << endl;
		cout << comp << endl;
		ans = (1 / 2) * ab * comp;

		fin[i] = ans;
	}

	for (int i = 0; i < 6; i++) {
		cout << fin[i] << endl;
	}
}