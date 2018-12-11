#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
int ReadArray(T** arr, int size, string file_name);

template <class T>
void PrintArray(T** arr, int size);

template <class T>
void CyclePush(T** arr, int size, int shift);

template <class T>
int Execute(string file_name);

int main() {

	string select;
selection:
	cout << "Select the data type (0 - integer, 1 - double, 2 - float): ";
	cin >> select;
	if (select == "0") {
		Execute<int>("integer.txt");
	}
	else if (select == "1") {
		Execute<double>("double.txt");
	}
	else if (select == "2") {
		Execute<float>("float.txt");
	}
	else {
		cout << "Error input! (Only 0, 1 or 2).\n\n";
		goto selection;
	}

	return 0;
}

template <class T>
int Execute(string file_name) {
	int size = 3;

	T** arr = new T*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new T[size];

	if (ReadArray(arr, size, file_name))
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

template <class T>
int ReadArray(T** arr, int size, string file_name) {
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

template <class T>
void PrintArray(T** arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++)
			cout << setw(3) << arr[i][j] << setw(2) << "|";
		cout << endl;
	}
}

template <class T>
void CyclePush(T** arr, int size, int shift) {
	T* a = new T[size];
	T* b = new T[size];
	T* c = new T[size];
	T* d = new T[size];
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