// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int a[n + 1];
	long long sum[n + 1];
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int t, l, r;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> l;
			sum[l] += (a[l + 1] - a[l]);
			swap(a[l], a[l + 1]);
		} else {
			cin >> l >> r;
			cout << sum[r] - sum[l - 1] << endl;
		}
	}
}
