#include "Partition.h"
#include "Global.h"
int Partition::partition(double arr[], int begin, int end) {

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
