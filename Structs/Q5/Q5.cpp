/*There is a structure called employee that holds information like employee code, name and date of joining.
Write a program to create an array of structures and enter some data into it. Then ask the user to enter
current date. Display the names of those employees whose tenure is greater than equal to 3 years.*/

#include<iostream>
using namespace std;

struct Date
{
	int date;
	int month;
	int year;
};

struct Employee
{
	int employee_code;
	const char* name;
	Date date_of_joining;
};


void func(Employee details[5], Date current_date)
{
	for (int i = 0; i < 5; i++) {
		if (current_date.year - details[i].date_of_joining.year >= 3) {
			cout << details[i].employee_code << "\t" << details[i].name <<
				"\t" << details[i].date_of_joining.date << "/" <<
				details[i].date_of_joining.month << "/" << details[i].date_of_joining.year << endl;
		}
	}
}


int main()
{
	Date d1 = { 13, 07, 2016 };
	Date d2 = { 22, 01, 2017 };
	Date d3 = { 14, 02, 2019 };
	Date d4 = { 28, 04, 2020 };
	Date d5 = { 11, 06, 2021 };
	Date current_date = { 01, 04, 2022 };

	Date joining_dates[] = { d1, d2, d3, d4, d5 };

	Employee s1 = { 190867984, "Keerat", d1 };
	Employee s2 = { 190564784, "Tani",  d2 };
	Employee s3 = { 190302984, "Simran", d3 };
	Employee s4 = { 190302934, "Anshika", d4 };
	Employee s5 = { 190302924, "Gigmet", d5 };

	Employee details[] = { s1, s2, s3, s4, s5 };
	func(details, current_date);
}