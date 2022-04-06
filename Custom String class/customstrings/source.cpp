#include "customstrings.hpp"
#include <iostream>
#include <string>

int main()
{
	String s("an ipad and a samsung galaxy");
	s.print();
	s.concatenate("war");
	s.print();
	s.to_uppercase();
	s.print();
	s.to_lowercase();
	s.print();
	s.to_titlecase();
	s.print();
	s.reverse_string();
	s.print();
	String s2(s);
	s2.print();
	String s4("wa war war warrrrrrr");
	String s3 = s + s4;
	s3.print();
	String s5;
	s5 = s3;
	s5.print();
	String s6;
	s6 = "dsfasfad";
	s6.print();
	s6 = "wa war warr warrr" + s +"dskfhskdfh" + "asdas" + s2;
	s6.print();
}