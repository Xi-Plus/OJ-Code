// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int BIT[1000005];
void update(int x, int v) {
	while (x < 1000005) {
		BIT[x] += v;
		x += x & -x;
	}
}
int query(int x) {
	int ans = 0;
	while (x > 0) {
		ans += BIT[x];
		x -= x & -x;
	}
	return ans;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, d;
	cin >> n >> d;
	vector<pair<int, int>> v1(n), v2;
	for (int i = 0; i < n; i++) {
		cin >> v1[i].first >> v1[i].second;
		v2.push_back({v1[i].second, v1[i].first});
	}
	int id1 = 0, id2 = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	long long ans = 0, cnt;
	for (int t = 1; t <= 1000000; t++) {
		cnt = query(t - d);
		ans += cnt * (cnt - 1) / 2;
		while (id1 < n && v1[id1].first <= t) {
			update(v1[id1].first, 1);
			id1++;
		}
		while (id2 < n && v2[id2].first <= t) {
			update(v2[id2].second, -1);
			id2++;
		}
	}
	cout << ans << endl;
}
