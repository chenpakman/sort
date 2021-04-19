#ifndef __SELECTION_H_
#define __SELECTION_H_

class Selection {

public:
	//int partition(double arr[], int begin, int end);
	//void swap(double& a, double& b);
	double selection(double arr[], int left, int right, int i);
	double runTime(double arr[], int left, int right, int i);
};
#endif