/*This program will get test scores from the user, sort the scores calculate the average score, 
drop the lowest score and output the sorted scores and average.
AJ Cox
4/21/2026*/

#include <iostream>
using namespace std;

int EnterScores(int* pointer, int size);
int SortFunction(int* pointer, int size);

int main()
{
	int size;

	cout << "Hello!" << endl << "How many test scores will you be entering: ";
	cin >> size;

	int* testptr = new int[size];

	EnterScores(testptr, size);
	SortFunction(testptr, size);
	
	for (int i = 0; i < size; i++)
		cout << *(testptr + i) << endl;


	delete[] testptr;
}

// EnterScores lets the user input thier test scores.
int EnterScores(int* pointer, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter test score #" << i + 1 << ": ";
		cin >> *(pointer + i);
	}
	return *pointer;
}

int SortFunction(int* pointer, int size)
{
	int minIndex, minValue;

	for (int i = 0; i < (size - 1); i++)
	{
		minIndex = i;
		minValue = *(pointer + i);
		for (int j = i + 1; j < size; j++)
		{
			if (*(pointer + i) < minValue)
			{

				minValue = *(pointer + j);
				minIndex = j;
			}
		}
		swap()
	}
}
