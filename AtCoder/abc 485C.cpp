// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int c[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int a[n + 1] = {}, b[n + 1] = {};
	for (int i = 2; i <= n; i++) {
		if (c[i] != c[i - 1]) {
			for (int j = 1; i - j >= 1 && a[i - j] == 0; j++) {
				a[i - j] = j;
			}
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		if (c[i] != c[i + 1]) {
			for (int j = 1; i + j <= n && b[i + j] == 0; j++) {
				b[i + j] = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			cout << b[i];
		} else if (b[i] == 0) {
			cout << a[i];
		} else {
			cout << min(a[i], b[i]);
		}
		cout << " ";
	}
	cout << "\n";
}
