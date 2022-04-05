/*Write a function that compares two given dates.To store a date use a structure that contains
three members namely day, monthand year. If the dates are equal the function should return 0,
otherwise it should return 1.*/

#include<iostream>
using namespace std;

struct Date
{
	int date;
	int month;
	int year;
};

int func(Date joining_dates[2])
{
	int i = 0;
	if (joining_dates[i].date == joining_dates[i + 1].date) {
		return 0;
	}
	else {
		return 1;
	}
}

int main()
{
	Date d1 = { 13, 07, 2018 };
	Date d2 = { 22, 01, 2017 };
	Date d3 = { 13, 07, 2018 };

	Date joining_dates[] = { d1, d3 };
	cout << func(joining_dates) << endl;
}