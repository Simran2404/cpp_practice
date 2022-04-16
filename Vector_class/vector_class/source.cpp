#include "vector_class.hpp"
#include "customstrings.hpp"
#include <iostream>
#include <string>
#include<cassert>
#include<vector>

int main()
{
	Vector<String> arr;
	Vector<int> ar;
	//String s = "simran";
	arr.pushback("simran");
	arr.pushback("malab");
	arr.pushback("gurnoor");
	//arr.print();
	arr.popback();
	//arr.print();

	ar.pushback(56);
	ar.pushback(13);
	ar.pushback(32);
	ar.pushback(38);
	ar.pushback(36);
	ar.insert(4, 245);
	ar.print();
	cout << "\n";
	ar.remove(5);
	ar.print();
	cout << "\n";
}
