#include "Insertion.h"

double Insertion:: insertionSort(double arr[], int size, int i) {
	double key;
	int j;

	for (int k = 1; k < size; k++) {
		key = arr[k];
		j = k;
		while (arr[j - 1] > key && j > 0) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
	return arr[i - 1];
}

double Insertion::runTime(double arr[], int size, int i) {
	double number_i;
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	number_i = insertionSort(arr, size, i);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile;
	myfile.open("Measure.txt", std::ios::app); // The name of the file

	myfile << "Time taken by function insertionSort is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	return number_i;
}
