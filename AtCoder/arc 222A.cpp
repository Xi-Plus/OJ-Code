// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
	int n, m;
	cin >> n >> m;
	int d = 0;
	int l, r;
	while (m--) {
		cin >> l >> r;
		d = max(d, r - l + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << (i % d) + 1 << " ";
	}
	cout << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
