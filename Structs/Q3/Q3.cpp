/*An automobile company has serial number for engine parts starting from AA0 to FF9.
The other characteristics of parts are year of manufacture, material and quantity manufactured.
(1) Specify a structure to store information corresponding to a part.
(2) Write a program to retrieve information on parts with serial numbers between BB1 and CC6.*/

#include<iostream>
using namespace std;

struct Auto
{
	const char* serial_no;
	const char* material;
	int quantity;
	int year_of_manufacture;
};

void func(Auto automobile[4])
{
	int pos, position;
	const char* upper = "CC6";
	const char* lower = "BB1";
	for (int i = 0; i < 6; i++) {
		if ("BB1" == automobile[i].serial_no) {
			pos = i;
		}

		if ("CC6" == automobile[i].serial_no) {
			position = i;
		}
	}

	for (int j = pos; j < position; j++) {
		cout << automobile[j].serial_no << "\t" << automobile[j].material << "\t" << automobile[j].quantity
			<< "\t" << automobile[j].year_of_manufacture << endl;
	};
}

int main()
{
	Auto b1 = { "AA0", "tungsten", 2, 2019 };
	Auto b2 = { "AB0", "steel", 1, 2023 };
	Auto b3 = { "BB1", "iron", 7, 2018 };
	Auto b4 = { "BA1", "brass", 3, 2015 };
	Auto b5 = { "CA4", "plastic", 4, 2012 };
	Auto b6 = { "CC6", "titanite", 3, 2010 };

	Auto automobile[] = { b1, b2, b3, b4, b5, b6 };
	func(automobile);
}