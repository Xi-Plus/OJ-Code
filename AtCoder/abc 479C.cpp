// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, w;
	cin >> n >> w;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	long long ans = 0, ww, val;
	for (long long i = 0; i < (1 << n); i++) {
		ww = 0;
		val = 0;
		for (long long j = 0; j < n; j++) {
			if (i & (1 << j)) {
				ww += b[j];
				val += a[j];
			}
		}
		if (ww <= w) {
			ans = max(ans, val);
		}
	}
	cout << ans << endl;
}
