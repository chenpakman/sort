#include "Quintuplet.h"
#include "Selection.h"
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
	int sizeB = n / 5;
	double* B = new double[sizeB];
	Selection s2;
	int k;
	int j = 0;
	if (n <= 5) {
		BubbleSort(arr, n);
		swap(arr[i - 1], arr[n - 1]);
		return arr[n-1];
	}
	else {
		for (int t = 0;t < n; t += 5) {

			BubbleSort(arr + t, 5);
			if (j < sizeB && (t % 5 == 0)) {
				B[j] = arr[t + 2];
				j++;
			}
			
		}

		double pivot = quintuplet(B, sizeB , (sizeB+1) / 2);
	//	delete[] B;
		
		
		 k = s2.partition(arr, 0, n - 1);
		if (k > i) {
			 quintuplet(arr, k, i);
		}
		if (k < i) {
			
			 quintuplet(arr+k+1, n-k, i - k);
		
		}
		else {
			return pivot;
			
		}

	}
}