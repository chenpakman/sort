#ifndef __GLOBAL_H_
#define __GLOBAL_H_
#include <string>
using namespace std;

inline void swap(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}

inline bool isNumber(char ch) {
	if (ch < '0' || ch>'9')
	{
		return false;
	}
	return true;
}

inline bool isValidInput(string input) {
	int inputLen = input.length();
	int countAfterPoint = 0;
	int index = 0;
	if (input[index] == '-') {
		index++;
	}
	while (input[index] != '.') {

		if (inputLen == index || !isNumber(input[index]))//Check if there is no '.'
		{
			return false;
		}
		index++;
	}
	if (input[index] == '.' && inputLen - 1 == index)// Check if the last char is '.'
	{
		return false;
	}
	index++;
	if (input[index] == '.') { // check if there is more than one point
		return false;
	}
	while (index != inputLen) {
		countAfterPoint++;
		if (countAfterPoint >= 5 || !isNumber(input[index]) || input[index] == '.') //Check if there is more than 4 digits after the point.
		{
			return false;
		}

		index++;
	}
	return true;
}

inline void copyArr(double* toArr, double* fromArr, int size) {
	for (int i = 0; i < size; i++) {
		toArr[i] = fromArr[i];
	}

}


#endif
