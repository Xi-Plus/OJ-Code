// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, rr;
	cin >> n >> rr;
	bool x[n], y[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (x[i]) {
			ans += 2;
		} else {
			ans++;
		}
	}
	for (int i = 0; i < min(n, rr); i++) {
		if (x[i] == 1) {
			ans -= 2;
		} else {
			break;
		}
	}
	for (int i = n - 1; i >= rr; i--) {
		if (x[i] == 1) {
			ans -= 2;
		} else {
			break;
		}
	}
	cout << ans << endl;
}
