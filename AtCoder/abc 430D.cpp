// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	set<int> s;
	unordered_map<int, int> dist;
	s.insert(0);
	int x;
	cin >> x;
	s.insert(x);
	long long ans = x * 2;
	cout << ans << endl;
	dist[0] = x;
	dist[x] = x;
	int lv, rv;
	for (int i = 1; i < n; i++) {
		cin >> x;
		auto it = s.upper_bound(x);
		if (it == s.end()) {
			lv = *prev(it);
			// cout << "last lv=" << lv << endl;
			ans -= dist[lv];
			dist[lv] = min(dist[lv], x - lv);
			ans += dist[lv];
			dist[x] = x - lv;
			ans += dist[x];
		} else {
			lv = *prev(it);
			rv = *it;
			// cout << "lv=" << lv << " rv=" << rv << endl;
			ans -= dist[lv];
			dist[lv] = min(dist[lv], x - lv);
			ans += dist[lv];
			ans -= dist[rv];
			dist[rv] = min(dist[rv], rv - x);
			ans += dist[rv];
			dist[x] = min(x - lv, rv - x);
			ans += dist[x];
		}
		s.insert(x);
		cout << ans << endl;
	}
}
