#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a;
	cout << "Enter alpha -> ";
	cin >> a;

	double z1 = (sin(a) + cos(a)) / (cos(a) - sin(a));
	double z2 = tan(2 * a) + 1 / cos(2 * a);
	cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;

	return 0;
}