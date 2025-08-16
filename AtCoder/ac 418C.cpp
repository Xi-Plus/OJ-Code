// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<long long> prefix(n + 1);
	prefix[0] = 0;
	for (int i = 0; i < n; i++) {
		prefix[i + 1] = prefix[i] + v[i];
	}
	int b;
	while (q--) {
		cin >> b;
		if (b == 1) {
			cout << 1 << endl;
			continue;
		}
		if (b > v[n - 1]) {
			cout << -1 << endl;
			continue;
		}
		int idx = upper_bound(v.begin(), v.end(), b - 1) - v.begin();
		cout << prefix[idx] + (long long)(n - idx) * (b - 1) + 1 << endl;
	}
}
