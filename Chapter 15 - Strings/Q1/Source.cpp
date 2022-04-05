/*Write a program that extracts part of the given string from the specified position. For example, if the string is 
"Working with strings is fun ", then if from position 4, 4 characters are to be extracted then the program should return
string as "king".If the number of characters to be extracted is 0 then the program should extract
entire string from the specified position.*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char s[] = "Working with strings is fun ";
    int pos, num;
    char t[25];

    cout << "Enter the position and number of characters in the array" << endl;
    cin >> pos >> num;

    if (num == 0)
    {
        printf("%s", s);
    }

    int j = 0;
    for (int i = pos - 1; i < (pos + num); i++)
    {
        t[j] = s[i];
        j++;
    }

    t[j] = '\0';
    printf("%s\n", t);
    return 0;
}