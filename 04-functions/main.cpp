#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead() {
	cout << string(74, '-') << endl;
	cout << "|         x         ";
	cout << "|   cos(x)  (mine)  ";
	cout << "|   cos(x) (cmath)  ";
	cout << "| iterations |\n";
	cout << string(74, '-') << endl;
}

double ComputeSeries(double x, int &n, const int kMaxIters, double eps) {
	n = 1;
	double nth_term = 1;
	double f = nth_term;
	while (abs(nth_term) > eps) {
		nth_term = pow(-1, n) * pow(x, n * 2) / tgamma(n * 2 + 1);
		f += nth_term;
		n++;
		if (n > kMaxIters) break;
	}
	return f;
}

void PrintTableRow(double x, double f, int n, const int kMaxIters) {
	cout << "|" << setw(13) << x << setw(7) << "|" << setw(14);
	if (n <= kMaxIters)
		cout << f << setw(6) << "|";
	else
		cout << " limit is exceeded |";
	cout << setw(14) << cos(x) << setw(6) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
	const int kMaxIters = 1000;

	double xn, xk, dx, eps;
	cout << "Enter xn -> ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) -> ";
	cin >> xk;
	cout << "Enter dx (dx > 0) -> ";
	cin >> dx;
	cout << "Enter eps (eps > 0) -> ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		while (xn <= xk)
		{
			int n = 1;
			double f = ComputeSeries(xn, n, kMaxIters, eps);
			PrintTableRow(xn, f, n, kMaxIters);
			xn += dx;
		}
		cout << string(74, '-');
	}

	return 0;
}