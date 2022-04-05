// minimum absolute difference question

#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	vector<int> diff;

	int difference = 0;
	int num[] = { 1,4,4, 6,5,7,2,9,6,3,25,6,56,4,462,2,24 };

	//for (int i = 0; i < 15; i++) {
	//	difference = abs(num[i] - num[i + 1]);
	//	diff.push_back(difference);
	//}

	//int min = diff[0];
	//for (int i = 0; i < diff.size(); i++) {
	//	if (min > diff[i]) {
	//		min = diff[i];
	//	}
	//}

	int min = abs(num[0] - num[1]);
	for (int i = 0; i < 15; i++) {
		if (min > (abs(num[i] - num[i + 1]))) {
			min = (abs(num[i] - num[i + 1]));
		}
	}
	cout << min << endl;
}