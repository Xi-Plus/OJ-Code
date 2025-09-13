// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	long long x[n], y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < 100; i++) {
		int idx1, idx2;
		do {
			idx1 = rand() % n;
			idx2 = rand() % n;
		} while (idx1 == idx2);
		long long a = y[idx2] - y[idx1];
		long long b = x[idx1] - x[idx2];
		long long c = x[idx2] * y[idx1] - x[idx1] * y[idx2];
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a * x[j] + b * y[j] + c == 0) {
				cnt++;
			}
		}
		if (cnt > n / 2) {
			cout << "Yes" << endl;
			cout << a << " " << b << " " << c << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
