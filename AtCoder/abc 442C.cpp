// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt[n + 1] = {};
	int a, b;
	while (m--) {
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}
	long long t;
	for (int i = 1; i <= n; i++) {
		t = n - cnt[i] - 1;
		if (t < 3) {
			cout << 0 << " ";
		} else {
			cout << t * (t - 1) * (t - 2) / 6 << " ";
		}
	}
	cout << endl;
}
