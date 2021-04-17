#include "Quintuplet.h"
#include "Selection.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void Quintuplet::BubbleSort(double arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);

		}
	}
}
void Quintuplet::swap(double& x, double& y) {
	double temp = x;
	x = y;
	y = temp;
}
double Quintuplet::quintuplet(double arr[], int n, int i) {
	int sizeB;
	if (n % 5 == 0) {
		 sizeB = n / 5;
	}
	else {
		sizeB = n / 5+1;
	}
	double* B = new double[sizeB];
	Selection s2;
	int k;
	int j = 0;
	if (n <= 5) {
		BubbleSort(arr, n);
		return arr[i-1];
	}
	else {
		for (int t = 0;t < n; t += 5) {
			if (n - t >= 5) {
				BubbleSort(arr + t, 5);
				B[j] = arr[t + 2];
			}
			else {
				BubbleSort(arr + t, n-t);
				B[j] = arr[t+(n-t)/2-1];

			}
			
			j++;
			
		}

		
		double pivot = quintuplet(B, sizeB , (sizeB+1) / 2);
		for (int d = 0; d < n; d++) {
			if (arr[d] == pivot) {
				swap(arr[d], arr[n - 1]);
				break;
			}
		}
		delete[] B;
		
		
		 k = s2.partition(arr, 0, n - 1);
		if (k > i) {
			 return quintuplet(arr, k, i);
		}
		if (k < i) {
			
			return quintuplet(arr+k+1, n-k-1, i - k-1);
		
		}
		else {
			return arr[k-1];
			
		}

	}
}
void Quintuplet::runTime(double arr[], int n, int i) {
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	quintuplet(arr,n,i);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();

		// Calculating total time taken by the program.
		double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile;
	myfile.open("Measure.txt", std::ios::app); // The name of the file

	myfile << "Time taken by function Quintuplet is : " << fixed<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}