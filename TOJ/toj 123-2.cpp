#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	char a[2][n + 2];
	a[0][0] = 1;
	a[1][0] = 1;
	a[0][n + 1] = 1;
	a[1][n + 1] = 1;
	for (int q = 1; q <= n; q++) {
		cin >> a[0][q];
		a[0][q] -= '0';
	}
	for (int q = 1; q <= n; q++) {
		cin >> a[1][q];
		a[1][q] -= '0';
	}
	bool ok = true;
	for (int q = 1; q <= n; q++) {
		ok &= (a[0][q] | (a[1][q - 1] & a[1][q] & a[1][q + 1]));
	}
	if (ok) {
		cout << "FENDED OFF!" << endl;
	} else {
		cout << "FENESTRATION FORTIFICATION FAILURE!" << endl;
	}
}
