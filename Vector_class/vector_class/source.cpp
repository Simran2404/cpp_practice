#include "vector_class.hpp"
#include "customstrings.hpp"
#include <iostream>
#include <string>

int main()
{
	Vector<String> arr;
	//String s = "simran";
	arr.pushback("simran");
	arr.pushback("gurnoor");
	arr.pushback("malab");
	arr.print();
	cout << "\n";
	arr.popback();
	arr.print();
}
