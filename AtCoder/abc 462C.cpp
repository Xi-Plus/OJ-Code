// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int BIT[300005];

void update(int x) {
	while (x < 300005) {
		BIT[x]++;
		x += x & -x;
	}
}
int query(int x) {
	int ans = 0;
	while (x) {
		ans += BIT[x];
		x -= x & -x;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto& [x, y] : v) {
		if (query(y) == 0) {
			ans++;
		}
		update(y);
	}
	cout << ans << endl;
}
