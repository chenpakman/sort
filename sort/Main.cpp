#include <iostream>
#include <string>
#include <iomanip> 
#include "Selection.h"
#include "Quintuplet.h"
#include "Insertion.h"
using namespace std;
void copyArr(double* toArr, double* fromArr, int size);
bool isValidInput(string input, int& index);
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
	if (n < 0 || i>n) {
		cout << "wrong input" << endl;
		exit(0);
	}
	double* numbersForSelection;
	numbersForSelection = new double[n];
	double* numbersForQuintuplet;
	numbersForQuintuplet = new double[n];
	double* numbersForInsertion;
	numbersForInsertion = new double[n];
	for (int j = 0; j < n; j++) {
		cin >> input;
		index = 0;
		if (isValidInput(input, index)) {
			numbersForSelection[numbersIndex] = stod(input, &idx);
			numbersIndex++;
		}
		else {
			cout << "wrong input" << endl;
		}
	}
	copyArr(numbersForQuintuplet, numbersForSelection, n);
	copyArr(numbersForInsertion, numbersForSelection, n);
	s1.runTime(numbersForSelection, 0, n - 1, i);
	double selection_i = s1.selection(numbersForSelection, 0, n - 1, i);
	q1.runTime(numbersForQuintuplet, n, i);
	double quintuplet_i = q1.quintuplet(numbersForQuintuplet, n, i);
	i1.runTime(numbersForInsertion, n, i);
	double insertion_i = i1.insertionSort(numbersForInsertion, n, i);
	cout << "Insertion sort i'th element: " << endl;
	cout << std::fixed << std::setprecision(4) << insertion_i << endl;
	cout << "Selection i'th element: "<<endl;
	cout << std::fixed << std::setprecision(4) << selection_i << endl;
	
	cout << "Quintuplet algorithm i'th element: " << endl;
	cout << std::fixed << std::setprecision(4) << quintuplet_i << endl;
	

	delete[] numbersForSelection;
	delete[] numbersForQuintuplet;
	delete[] numbersForInsertion;

	
}

bool isValidInput(string input, int& index) {
	int inputLen = input.length();
	int countAfterPoint = 0;
	while (input[index] != '.') {

		if (inputLen == index) {

			break;
		}
		index++;
	}
	if (input[index] == '.' && inputLen - 1 == index)
	{
		return false;
	}
	while (index != inputLen - 1) {
		countAfterPoint++;
		if (countAfterPoint >= 5) {
			return false;
		}

		index++;
	}
	return true;
}
void copyArr(double* toArr, double* fromArr, int size) {
	for (int i = 0; i < size; i++) {
		toArr[i] = fromArr[i];
	}

}