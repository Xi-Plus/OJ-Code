// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int a, d, b;
	bool operator<(const Node& rhs) const {
		return d < rhs.d;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> cnt;
	int ans = 0;
	vector<Node> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].a >> v[i].d >> v[i].b;
		cnt[v[i].a]++;
		if (cnt[v[i].a] == 1) {
			ans++;
		}
	}
	sort(v.begin(), v.end());
	int idx = 0;
	for (int i = 1; i <= m; i++) {
		while (idx < n && v[idx].d <= i) {
			cnt[v[idx].a]--;
			if (cnt[v[idx].a] == 0) {
				ans--;
			}
			cnt[v[idx].b]++;
			if (cnt[v[idx].b] == 1) {
				ans++;
			}
			idx++;
		}
		cout << ans << endl;
	}
}
