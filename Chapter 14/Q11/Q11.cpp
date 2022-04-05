#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	double p[10][10] = { {3.0, 1.5},{4.5, 2.0}, {5.5, 3.5}, {6.5, 5.0 }, {7.5, 6.0},{8.5, 7.5},
		{8.0, 9.0}, {9.0, 10.5 },{9.5, 12.0},{10.0, 14.0 } };

	double sumx = 0;
	double sumy = 0;
	double sumxx = 0;
	double b = 0;
	double a = 0;
	double sumxy = 0;
	double temp = 0;

	for (int i = 0; i < 10; i++) {
		sumx = sumx + p[i][0];
		sumy = sumy + p[i][1];
		sumxx = sumxx + (p[i][0] * p[i][0]);
		sumxy = sumxy + (p[i][0] * p[i][1]);
	}

	double sumx2 = (sumx * sumx);
	double sumxy2 = (sumx * sumy);

	temp = ((10 * sumxx) - sumx2);

	b = (10 * sumxy - sumx * sumy) / sqrt(temp);
	a = sumy - b * sumx;
	cout << a << endl;
	cout << b << endl; 
}
