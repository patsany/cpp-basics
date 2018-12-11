#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void PrintArray(double arr[], const int kArraySize);
int CountZeroes(double arr[], const int kArraySize);
int FindMin(double arr[], const int kArraySize);
double SumAfterMin(double arr[], int min_addr, const int kArraySize);
void SortArray(double arr[], const int kArraySize);

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