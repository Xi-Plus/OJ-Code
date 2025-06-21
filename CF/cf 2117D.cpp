// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int a[200001];
	while (t--) {
		int n;
		cin >> n;
		for (int q = 1; q <= n; q++) {
			cin >> a[q];
		}
		bool ans = true;
		int apb = (a[1] + a[n]) / (n + 1);
		if ((a[1] + a[n]) % (n + 1) != 0) {
			ans = false;
		}
		int x = (a[n] - apb) / (n - 1);
		if ((a[n] - apb) % (n - 1) != 0) {
			ans = false;
		}
		int y = (a[1] - apb) / (n - 1);
		if ((a[1] - apb) % (n - 1) != 0) {
			ans = false;
		}
		if (x < 0 || y < 0) {
			ans = false;
		}
		if (ans) {
			for (int q = 2; q <= n - 1; q++) {
				if (a[q] != q * x + (n - q + 1) * y) {
					ans = false;
					break;
				}
			}
		}
		if (ans) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
