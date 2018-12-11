#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int ReadArray(int** arr, int size, string file_name);
void PrintArray(int** arr, int size);
void CyclePush(int** arr, int size, int shift);

int main() {
	int size = 3;

	int** arr = new int*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new int[size];

	if (ReadArray(arr, size, "file.txt"))
		return 1;
	cout << "Starting array:\n";
	PrintArray(arr, size);
	cout << endl;

	int k;
	cout << "Enter k > 0: ";
	cin >> k;

	cout << "\nShifted array:\n";
	CyclePush(arr, size, k);
	PrintArray(arr, size);

	for (int i = 0; i < size; i++) delete[] arr[i];
	delete[] arr;

	return 0;
}

int ReadArray(int** arr, int size, string file_name) {
	ifstream fin(file_name);
	if (!fin.is_open()) {
		cout << "Can't open file: " << file_name << endl;
		return 1;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fin >> arr[i][j];

	fin.close();
	return 0;
}

void PrintArray(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++)
			cout << setw(3) << arr[i][j] << setw(2) << "|";
		cout << endl;
	}
}

void CyclePush(int** arr, int size, int shift) {
	int* a = new int[size];
	int* b = new int[size];
	int* c = new int[size];
	int* d = new int[size];
	for (int rotation = 0; rotation < shift; rotation++) {
		for (int i = 0; i < size; i++) {
			a[i] = arr[0][i];
			b[i] = arr[size - i - 1][size - 1];
			c[i] = arr[size - 1][i];
			d[i] = arr[i][0];
		}
		for (int i = 0; i < size; i++) {
			arr[0][size - i - 1] = d[i];
			arr[i][size - 1] = a[i];
			arr[size - 1][i] = b[i];
			arr[i][0] = c[i];
		}
	}
}