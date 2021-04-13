#include "Selection.h"
#include <iostream>
using namespace std;


void Selection::swap(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}


int Selection::partition(double arr[], int begin, int end) {

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
}

double Selection::selection(double arr[], int left, int right, int i) {
    int pivot = partition(arr, left, right);
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