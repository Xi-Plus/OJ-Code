// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a;
	int cnt[k + 1] = {};
	int maxstu = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
		maxstu = max(maxstu, cnt[a]);
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (cnt[i] >= maxstu - 1) {
			ans++;
		}
	}
	cout << ans << endl;
}
