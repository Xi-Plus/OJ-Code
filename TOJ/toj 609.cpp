#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= n - q; w++) {
			cout << " ";
		}
		for (int w = 1; w <= q * 2 - 1; w++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int q = n - 1; q >= 1; q--) {
		for (int w = 1; w <= n - q; w++) {
			cout << " ";
		}
		for (int w = 1; w <= q * 2 - 1; w++) {
			cout << "*";
		}
		cout << endl;
	}
}
