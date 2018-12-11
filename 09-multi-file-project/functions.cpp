#include "functions.h"

void PrintArray(double arr[], const int kArraySize) {
	cout << string(81, '-') << "\n|";

	for (int i = 0; i < kArraySize; i++)
		cout << setw(3) << "[" << i << "]" << setw(3) << "|";

	cout << " <- index\n" << string(81, '-') << "\n|";

	for (int i = 0; i < kArraySize; i++)
		cout << setw(4) << arr[i] << setw(4) << "|";

	cout << " <- array\n" << string(81, '-');
}

int CountZeroes(double arr[], const int kArraySize) {
	int num_zeroes = 0;
	for (int i = 0; i < kArraySize; i++)
		if (arr[i] == 0)
			num_zeroes++;
	return num_zeroes;
}

int FindMin(double arr[], const int kArraySize) {
	int min_addr = 0;
	for (int i = 1; i < kArraySize; i++)
		if (arr[i] < arr[min_addr])
			min_addr = i;
	return min_addr;
}

double SumAfterMin(double arr[], int min_addr, const int kArraySize) {
	double sum_after_min = 0;
	for (int i = min_addr + 1; i < kArraySize; i++)
		sum_after_min += arr[i];
	return sum_after_min;
}

void SortArray(double arr[], const int kArraySize) {
	for (int i = 0; i < kArraySize - 1; i++)
		for (int j = 0; j < kArraySize - i - 1; j++)
			if (abs(arr[j]) > abs(arr[j + 1]))
				swap(arr[j], arr[j + 1]);
}