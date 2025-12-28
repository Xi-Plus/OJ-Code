// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, l;
	cin >> n >> l;
	long long v[300001] = {};
	int cur = 0, t;
	v[0]++;
	for (int q = 0; q < n - 1; q++) {
		cin >> t;
		cur = (cur + t) % l;
		v[cur]++;
	}
	if (l % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	for (int q = 0; q < l / 3; q++) {
		ans += v[q] * v[(q + l / 3) % l] * v[(q + 2 * l / 3) % l];
	}
	cout << ans << endl;
	return 0;
}
