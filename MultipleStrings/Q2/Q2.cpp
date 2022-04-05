/*Write a program that will read a line and delete from it all
occurrences of the word ‘the’.*/

#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

//function to check whether the word extracted and passed matches with 'the'
bool func(char str1[], char str2[]) {
	for (int i = 0; i < strlen(str2); i++) {
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	char str1[] = "the dog takes a walk at the local park in the countryside";
	char str2[] = "the";
	int length = strlen(str1);
	int sample = strlen(str2);
	int len = 0; //memory of each extracted word
	int pos = 0; //keeps track of which index we're at in the array 
	int counter = 0;
	char* a = nullptr;
	int newlen;
	vector<char*> result;

	//the first loop runs over the array as a whole
	for (int i = 0; i < length; i = pos) { //outer loop provides the index of the next word for extraction hence i=pos
		for (int j = i; j < length; j++) {  //j=i because we need to keep track and start at the next index
			if (str1[j] != ' ') {
				len++;  //calculating the length of each word in the array ini order to allocate memory
			}
			else {
				break;
			}
		}

		a = (char*)malloc((len + 1) * sizeof(char)); //allocating memory for individual words extracted

		for (int k = 0; k < len; k++) {  //adding each extracted word into memory 'a' to send to the function
			a[k] = str1[pos];
			pos++;
		}

		a[len] = '\0';

		pos += 1; //incrementing pos to accomodate the null at the end
		len = 0; //resetting len for the next iteration 

		if (func(a, str2))
		{
			counter++; //keeping a count of the number of occurences
		}

		newlen = (length - (sample * counter)) + 1;  //calculating newlen for the final memory allocation 

		if (func(a, str2) == false) {
			result.push_back(a);  //pushing the words that don't match into the vector 
		}
	}

	int position = 0;
	char* arr = (char*)malloc((newlen + 1) * sizeof(char));


	/*here we can treat the vector of words as a 2D matrix because it points to
	individual words and then to individual characters hence the two loops*/

	for (int p = 0; p < result.size(); p++) {
		for (int r = 0; r < strlen(result[p]); r++) {  //here result[p] will be the size of the first word 
			arr[position] = result[p][r];
			position++;
		}
		arr[position] = ' ';
		position++;
	}

	arr[position] = '\0';

	for (int p = 0; arr[p] != 0; p++) {
		cout << arr[p];
	}

	//we need to run a loop to free memory otherwise it'll only delete the last word memory
	for (int y = 0; y < result.size(); y++) {
		free(result[y]);
	}
	free(arr);
}

