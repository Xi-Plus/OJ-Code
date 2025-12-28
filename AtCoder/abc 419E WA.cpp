// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, l;
	cin >> n >> m >> l;
	int a[1005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long sum[1005];
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		// cout << sum[i] << " ";
	}
	// cout << endl;
	long long ans = 1e18;
	long long rsum[1005];
	int add;
	for (int i = 1; i <= l; i++) {
		// cout << "i = " << i << endl;
		for (int j = l; j <= n; j++) {
			rsum[j] = sum[j] - sum[j - l];
			// cout << rsum[j] << " ";
		}
		// cout << endl;
		add = (m - rsum[l] % m) % m;
		// cout << add << " ";
		long long tans = add;
		for (int j = l; j <= i + l - 1; j++) {
			rsum[j] += add;
		}
		for (int j = l + 1; j <= n; j++) {
			add = (m - rsum[j] % m) % m;
			tans += add;
			// cout << add << " ";
			for (int k = j; k <= j + l - 1 && k <= n; k++) {
				rsum[k] += add;
			}
		}
		// cout << endl;
		ans = min(ans, tans);
	}
	cout << ans << endl;
}
