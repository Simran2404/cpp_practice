/*The X and Y coordinates of 10 different points are entered through
the keyboard. Write a program to find the distance of last point
from the first point (sum of distances between consecutive points).*/

#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	double p[10][10] = { {0, 0},{1, 1}, {2, 2}, {3, 3 }, {4,4},{5, 5},
		{7, 7}, {8, 8 },{9, 9},{10, 10 } };

	double distance, sum = 0;

	for (int i = 0; i < 9; i++) {
		distance = sqrt(((p[i + 1][1] - p[i][1]) * (p[i + 1][1] - p[i][1])) + ((p[i + 1][0] - p[i][0]) * (p[i + 1][0] - p[i][0])));
		sum = sum + distance;
	}
	cout << sum << endl;
}

