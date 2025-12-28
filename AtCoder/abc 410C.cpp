// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int v[n + 1];
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	int offset = 0;
	int t, p, x;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> p >> x;
			v[(p - 1 + offset) % n] = x;
		} else if (t == 2) {
			cin >> p;
			cout << v[(p - 1 + offset) % n] << endl;
		} else {
			cin >> p;
			offset = (offset + p) % n;
		}
	}
}
