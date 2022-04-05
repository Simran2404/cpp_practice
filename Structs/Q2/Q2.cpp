/*Create a structure to specify data of customers in a bank. The data to be stored is : Account number,
Name, Balance in account. Assume maximum of 200 customers in the bank.
(1) Write a function to print the Account number and name of each customer with balance below Rs. 100.
(2) If a customer requests for withdrawal or deposit, the form contains the fields:
Acct.no, amount, code(1 for deposit, 0 for withdrawal)
Write a program to give a message, “The balance is insufficient for the specified withdrawal”,
if on withdrawal the balance falls below Rs. 100.*/

#include<iostream>
using namespace std;

struct Bank
{
	int account_no;
	const char* name;
	float balance;
	bool code;
};

void func(Bank stud[4])
{
	int balance = 100;
	for (int i = 0; i < 6; i++) {
		if (stud[i].balance < balance && stud[i].code == 0) {
			cout << stud[i].account_no << "\t" << stud[i].name << "\t" << stud[i].balance << endl;
			cout << "Tha balance is insufficient for the specified withdrawal\n";
		}
	}
}

int main()
{
	Bank b1 = { 190823938, "Gurnoor", 310.96, 0 };
	Bank b2 = { 190867984, "Agastya", 0.05, 1 };
	Bank b3 = { 190564784, "Malab", 0.08, 0 };
	Bank b4 = { 190302984, "Simsim", 98.24, 0 };
	Bank b5 = { 190823938, "Anshika", 43200, 1 };
	Bank b6 = { 190823938, "Amruta", 132, 1 };

	Bank bankers[] = { b1, b2, b3, b4, b5, b6 };
	func(bankers);
}