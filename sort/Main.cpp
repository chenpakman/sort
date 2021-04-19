#include <iostream>
#include <string>
#include <iomanip> 
#include "Selection.h"
#include "Quintuplet.h"
#include "Insertion.h"
#include "Global.h"
using namespace std;

int main() {
	string input;
	int n, i;
	int index = 0;
	int numbersIndex = 0;
	size_t idx = 0;
	Selection s1;
	Quintuplet q1;
	Insertion i1;
	
	cin >> n;
	cin >> i;

	if (n < 0 || i>n||i<=0) 
	{
		cout << "wrong input" << endl;
		exit(0);
	}

	double* numbersForSelection;
	numbersForSelection = new double[n];
	double* numbersForQuintuplet;
	numbersForQuintuplet = new double[n];
	double* numbersForInsertion;
	numbersForInsertion = new double[n];

	for (int j = 0; j < n; j++) 
	{
		cin >> input;
		
		if (isValidInput(input)) {
			numbersForSelection[numbersIndex] = stod(input, &idx);
			numbersIndex++;
		}
		else {
			cout << "wrong input" << endl;
			exit(0);
		}
	}

	copyArr(numbersForQuintuplet, numbersForSelection, n);
	copyArr(numbersForInsertion, numbersForSelection, n);
	
	double selection_i = s1.runTime(numbersForSelection, 0, n - 1, i);
	double quintuplet_i = q1.runTime(numbersForQuintuplet, n, i);
	double insertion_i = i1.runTime(numbersForInsertion, n, i);

	cout << "Insertion sort i'th element: ";
	cout << std::fixed << std::setprecision(4) << insertion_i << endl;
	cout << "Selection i'th element: ";
	cout << std::fixed << std::setprecision(4) << selection_i << endl;
	cout << "Quintuplet algorithm i'th element: " ;
	cout << std::fixed << std::setprecision(4) << quintuplet_i << endl;
	

	delete[] numbersForSelection;
	delete[] numbersForQuintuplet;
	delete[] numbersForInsertion;

	
}
