#include "customstrings.hpp"

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
}