#include "Selection.h"
#include "Partition.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;




/*int Selection::partition(double arr[], int begin, int end) {

    double pivot = arr[end];
    int i = begin - 1;

    for (int j = begin; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}*/

double Selection::selection(double arr[], int left, int right, int i) {
    Partition p;
    int pivot = p.partition(arr, left, right);
    int leftPart;
    leftPart = pivot - left + 1;
        if (i == leftPart) {
        return arr[pivot];
    }
    if (i < leftPart) {
        return selection(arr, left, pivot - 1, i);
    }
    else {
        return selection(arr, pivot + 1, right, i - leftPart);
    }
}
double Selection::runTime(double arr[], int left, int right, int i) {
    double number_i;
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    number_i= selection(arr, left,right, i);// Here you put the name of the function you wish to measure
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    ofstream myfile("Measure.txt"); // The name of the file
    myfile << "Time taken by function selection is : " << fixed << time_taken << setprecision(9);
    myfile << " sec" << endl;
    myfile.close();
    return number_i;
}