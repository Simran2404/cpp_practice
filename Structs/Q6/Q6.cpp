/*Create a structure called library to hold accession number, title of the book, author name,
price of the book, and flag indicating whether book is issued or not. Write a menu - driven program
that implements the working of a library.The menu options should be :
1. Add book information
2. Display book information
3. List all books of given author
4. List the title of specified book
5. List the count of books in the library
6. List the books in the order of accession number
7. Exit*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Library
{
	int accession_no;
	char title[50];
	char author[50];
	int price;
	bool issue;
};

void Display(Library books[50], int top)
{
	for (int i = 0; i < top; i++) {
		cout << books[i].accession_no << "\t" << books[i].title << "\t" << books[i].author
			<< "\t" << books[i].price << endl;

	}
}

void Author_Display(Library books[50], const char* author_name, int top)
{
	for (int i = 0; i < top; i++) {
		if (strcmp(books[i].author, author_name) == 0) {
			cout << books[i].accession_no << "\t" << books[i].title << "\t" << books[i].author
				<< "\t" << books[i].price << endl;
		}
	}
}

void Book_Display(Library books[50], int accession, int top)
{
	for (int i = 0; i < top; i++) {
		if (books[i].accession_no == accession)
			cout << books[i].accession_no << "\t" << books[i].title << "\t" << books[i].author
			<< "\t" << books[i].price << endl;
	}
}

int compare(void const* a, void const* b)
{
	return ((Library*)a)->accession_no > ((Library*)(b))->accession_no;
}

int main()
{
	Library b1 = { 145678, "Normal People", "Sally Rooney", 540, true };
	Library b2 = { 768592, "Beautiful World - Where are you", "Sally Rooney", 610, true };
	Library b3 = { 526573, "Sweet Bean Paste", "Durian Sukegawa", 220, false };
	Library b4 = { 892703, "Harry Potter", "J. K. Rowling", 430, false };
	Library b5 = { 763529, "Dance, Dance, Dance!", "Haruki Murakami", 670, false };
	Library b6 = { 462920, "Norwegian Wood", "Haruki Murakami", 180, true };
	Library b7 = { 321793, "Such a fun age", "Kylie Reid", 240, false };
	Library b8 = { 628942, "Red, White and Royal Blue", "Casey McQuiston", 890, true };
	Library b9 = { 319273, "Exciting Times", "Naoise Dolan", 360, false };
	Library b10 = { 624381, "Before the coffee gets cold", "Toshikazu Kawaguchi", 970, true };

	Library books[50] = { b1, b2, b3, b4, b5, b6, b7, b8, b9, b10 };
	int top = 10;
	const char* author_name = "Sally Rooney";
	int accession = 462920;
	int choice = 1;

	cout << "Your Library Menu: \n";
	cout << "1. Add book information \n";
	cout << "2. Display book information \n";
	cout << "3. List all books of given author\n";
	cout << "4. List the title of specified book\n";
	cout << "5. List the count of books in the library\n";
	cout << "6. List the books in the order of accession number\n";
	cout << "7. Exit\n";

	while (choice) {

		cout << "Please enter your choice!\n";
		cin >> choice;

		int entries;

		switch (choice) {
			case 1: {
				cout << "Enter the number of entries you wish to do:\n";
				cin >> entries;
				int length = top + entries;
				for (int i = top; i < length; i++, top++) {
					cin >> books[i].accession_no >> books[i].title >> books[i].author >> books[i].price;
				}
				Display(books, top);
				break;
			}
			case 2: {
				Display(books, top);
				break;
			}
			case 3: {
				Author_Display(books, author_name, top);
				break;
			}
			case 4: {
				Book_Display(books, accession, top);
				break;
			}
			case 5: {
				cout << "The number of books in the library are:" << top << endl;
				break;
			}
			case 6: {
				qsort(books, 10, sizeof(Library), compare);
				for (int i = 0; i < 6; i++) {
					cout << books[i].accession_no << "\t" << books[i].title << "\t" << books[i].author
						<< "\t" << books[i].price << endl;
				}
				break;
			}
			case 7: {
				return 0;
			}
		};
	}
}