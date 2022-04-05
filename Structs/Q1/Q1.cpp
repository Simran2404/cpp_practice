/*Create a structure to specify data on students given below: Roll number, Name, Department, Course, Year of joining.
Assume that there are not more than 450 students in the college. (1) Write a function to print names of all students
who joined in a particular year. (2) Write a function to print the data of a student whose roll number is received
by the function.*/

#include<iostream>
using namespace std;

struct Student
{
	int roll_no;
	const char* name;
	const char* department;
	const char* course;
	int join;
};

void func(int roll, Student stud[4])
{
	for (int i = 0; i < 4; i++) {
		if (stud[i].roll_no == roll) {
			cout << stud[i].roll_no << "\t" << stud[i].name << "\t" << stud[i].department << "\t" <<
				stud[i].course << "\t" << stud[i].join << endl;
		}
	}
}

int main()
{
	Student s = { 190823938, "Gurnoor", "ICT", "Information Technology", 2019 };
	Student s1 = { 190867984, "Agastya", "Domestic Violence", "Brutality", 2023 };
	Student s2 = { 190564784, "Malab", "Gym Chads", "Push ups", 2019 };
	Student s3 = { 190302984, "Simsim", "BTS", "Map of the Soul", 2022 };

	Student stud[] = { s, s1, s2, s3 };
	int year = 2019;
	for (int i = 0; i < 4; i++) {
		if (stud[i].join == 2019) {
			cout << stud[i].roll_no << "\t" << stud[i].name << "\t" << stud[i].department << "\t" <<
				stud[i].course << "\t" << stud[i].join << endl;
		}
	}

	int roll = 190867984;
	func(roll, stud);
}