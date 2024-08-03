// By xiplus
#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int fac = 2;
		if (n == 1) cout << "1";
		while (n != 1) {
			int pow = 0;
			while (n % fac == 0) {
				pow++;
				n /= fac;
			}
			if (pow > 0) {
				cout << fac;
				if (pow > 1) {
					cout << "^" << pow;
				}
				if (n != 1) {
					cout << " * ";
				}
			}
			fac++;
		}
		cout << endl;
	}
	return 0;
}
