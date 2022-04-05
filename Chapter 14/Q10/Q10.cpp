#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	double p[11][11] = { {34.22, 102.43}, {39.87, 100.93}, {41.85, 97.43}, {43.23, 97.81}, {40.06, 98.32}, {53.29, 98.32},
		{53.29, 100.07}, {54.14, 97.08}, {49.12, 91.59}, {40.71, 94.85}, {55.15, 94.65} };

	double sumx = 0;
	double sumy = 0;
	double sumxx = 0;
	double sumyy = 0;
	double ans = 0;
	double sumxy = 0;
	double temp = 0;

	for (int i = 0; i < 11; i++) {
		sumx = sumx + p[i][0];
		sumy = sumy + p[i][1];
		sumxx = sumxx + (p[i][0] * p[i][0]);
		sumyy = sumyy + (p[i][1] * p[i][1]);
		sumxy = sumxy + (p[i][0] * p[i][1]);
	}
	double sumx2 = (sumx * sumx);
	double sumy2 = (sumy * sumy);
	double sumxy2 = (sumx * sumy);
	temp = ((11 * sumxx) - sumx2) * ((11 * sumyy) - sumy2);
	ans = (11*sumxy - sumxy2) / sqrt(temp);
	cout << ans << endl;
}
