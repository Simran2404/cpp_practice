/*A record contains name of cricketer, his age, number of test matches that he has played and the
average runs that he has scored in each test match. Create an array of structures to hold records of
20 such cricketers and then write a program to read these records and arrange them in ascending order
by average runs. Use the qsort( ) standard library function.*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Cricketer
{
	const char* name;
	int age;
	int test_matches;
	int average_runs;
};

int compare_cricketer(void const* a, void const* b)
{
	return ((Cricketer*)a)->average_runs > ((Cricketer*)(b))->average_runs;
}

int main()
{
	Cricketer b1 = { "Sachin", 22, 190, 200 };
	Cricketer b2 = { "Dhoni", 34, 150, 200 };
	Cricketer b3 = { "Sehwag", 42, 110, 176 };
	Cricketer b4 = { "Yuvraj", 32, 150, 80 };
	Cricketer b5 = { "Hardik", 27, 167, 140 };
	Cricketer b6 = { "Harbhajan", 29, 140, 130 };

	Cricketer details[] = { b1, b2, b3, b4, b5, b6 };
	qsort(details, 6, sizeof(Cricketer), compare_cricketer);

	for (int i = 0; i < 6; i++) {
		cout << details[i].name << "\t" << details[i].age << "\t" << details[i].test_matches <<
			"\t" << details[i].average_runs << endl;

	}
}