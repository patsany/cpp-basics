#include "functions.h"

int main() {
	int const kArraySize = 10;
	double arr[kArraySize] = { 0, -1, 0, .3, -4, .5, 6, -7, 0, -.9 };

	cout << "Starting array:\n";
	PrintArray(arr, kArraySize);
	cout << endl;

	cout << "\nNumber of zero elements: ";
	cout << CountZeroes(arr, kArraySize);
	cout << endl;

	int min_addr = FindMin(arr, kArraySize);
	cout << "\nSum of elements after min element = ";
	if (min_addr < kArraySize - 1)
		cout << SumAfterMin(arr, min_addr, kArraySize);
	else
		cout << "min element is the last one";
	cout << endl;

	cout << "\nSorted array:\n";
	SortArray(arr, kArraySize);
	PrintArray(arr, kArraySize);

	return 0;
}