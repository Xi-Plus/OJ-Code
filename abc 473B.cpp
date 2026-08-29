// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	int cnt[105] = {};
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cnt[t]++;
	}
	int ans = 0;
	for (int i = 0; i < 105; i++) {
		if (cnt[i] & 1) {
			ans += i;
		}
	}
	cout << ans << endl;
}
