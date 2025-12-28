// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> v(n + 1), sum(n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}
	int t, c, l, r, offset = 0;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> c;
			offset = (offset + c) % n;
		} else {
			cin >> l >> r;
			l = (l - 1 + offset) % n + 1;
			r = (r - 1 + offset) % n + 1;
			if (l > r) {
				cout << sum[n] - sum[l - 1] + sum[r] << endl;
			} else {
				cout << sum[r] - sum[l - 1] << endl;
			}
		}
	}
}
