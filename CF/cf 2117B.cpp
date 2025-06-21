// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int q = 0; q < n / 2; q++) {
			cout << (q + 1) * 2 << " ";
		}
		for (int q = (n - 1) / 2; q >= 0; q--) {
			cout << q * 2 + 1 << " ";
		}
		cout << endl;
	}
}
