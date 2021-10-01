#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, w;
	cin >> t;
	for (int q = 0; q < t; q++) {
		cout << "Case " << q + 1 << ":" << endl;
		cin >> n;
		w = (n + 1) / 2 * 2 + 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (i + 1) / 2; j++) {
				cout << "*";
			}

			if (n - i + 1 <= n / 3) {
				for (int j = 0; j < w - (i + 1) / 2 * 2; j++) {
					cout << "~";
				}
			} else {
				for (int j = 0; j < w - (i + 1) / 2 * 2; j++) {
					cout << " ";
				}
			}

			for (int j = 0; j < (i + 1) / 2; j++) {
				cout << "*";
			}

			cout << endl;
		}
	}
}
