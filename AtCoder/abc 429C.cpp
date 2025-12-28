// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	unordered_map<int, long long> cnt;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}
	if (cnt.size() == 1) {
		cout << 0 << endl;
	} else {
		long long ans = 0;
		for (auto [v, c] : cnt) {
			if (c >= 2) {
				ans += c * (c - 1) / 2 * (n - c);
			}
		}
		cout << ans << endl;
	}
}
