// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int l[n + 1], r[n + 1], lmin[n + 1], rmin[n + 1];
	for (int i = 2; i <= n; i++) {
		cin >> l[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		cin >> r[i];
	}
	rmin[1] = r[1];
	for (int i = 2; i <= n - 1; i++) {
		rmin[i] = min(rmin[i - 1], r[i]);
	}
	lmin[n] = l[n];
	for (int i = n - 1; i >= 2; i--) {
		lmin[i] = min(lmin[i + 1], l[i]);
	}
	int s, t;
	while (q--) {
		cin >> s >> t;
		if (s < t) {
			cout << min(r[s], l[s] + rmin[s]) << endl;
		} else {
			cout << min(l[s], r[s] + lmin[s]) << endl;
		}
	}
}
