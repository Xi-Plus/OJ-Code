#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[2][n];
	char c;
	for (int q = 0; q < n; q++) {
		cin >> c;
		a[0][q] = c - '0';
	}
	for (int q = 0; q < n; q++) {
		cin >> c;
		a[1][q] = c - '0';
	}
	bool failed = false;
	for (int q = 0; q < n - 1; q++) {
		if (a[0][q] + a[0][q + 1] == 2) {
			//ok
		} else if (a[1][q] + a[1][q + 1] == 2) {
			//ok
		} else if (a[0][q] + a[1][q] + a[0][q + 1] + a[1][q + 1] >= 3) {
			//ok
		} else {
			failed = true;
		}
	}
	if (failed) {
		cout << "FENESTRATION FORTIFICATION FAILURE!" << endl;
	} else {
		cout << "FENDED OFF!" << endl;
	}
}