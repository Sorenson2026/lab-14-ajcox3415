/*This program will get test scores from the user, sort the scores calculate the average score, 
drop the lowest score and output the sorted scores and average.
AJ Cox
4/21/2026*/

#include <iostream>
using namespace std;

//function prototypes
void EnterScores(int* pointer, int size);
void SortFunction(int* pointer, int size);
void swap(int& a, int& b);
void average(int* pointer, int size);

// Main will get the amout of test scores and call the other funcitons
int main()
{
	int size;

	//Gets size
	cout << "Hello!" << endl << "How many test scores will you be entering: ";
	cin >> size;

	int* testptr = new int[size];

	//Calls functions
	EnterScores(testptr, size);
	SortFunction(testptr, size);
	
	//outputs sorted test scores
	cout << endl << "Here are the test scores sorted in assending order: " << endl;

	for (int i = 0; i < size; i++)
		cout << *(testptr + i) << " ";

	average(testptr, size);


	delete[] testptr;
}

// EnterScores lets the user input thier test scores.
void EnterScores(int* pointer, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter test score # " << i + 1 << " (Please no negitives): ";
		cin >> *(pointer + i);

		//Input Validiation
		if (*(pointer + i) < 0)
		{
			cout << "PLease no negitives. Try again: ";
			cin >> *(pointer + i);
		}
	}
	
}

//This function will sort the scores useing selectin sort.
void SortFunction(int* pointer, int size)
{
	int minIndex, minValue;

	for (int i = 0; i < (size - 1); i++)
	{
		minIndex = i;
		minValue = *(pointer + i);

		for (int j = i + 1; j < size; j++)
		{
			if (*(pointer + j) < minValue)
			{

				minValue = *(pointer + j); 
				minIndex = j;
			}
		}
		//Calls swap function
		swap(*(pointer + minIndex), *(pointer + i));
	}
	
}

// This will swap the scores.
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Calculates the average and dropps the lowest score.
void average(int* pointer, int size)
{
	float total = 0.0;
	float average;

	//calculates average
	for (int i = 1; i < size; i++)
	{
		total += *(pointer + i);
	}
	average = total / size;

	cout << endl << endl << "After the lowest score was dropped, the average test score is: " << average << endl;
}