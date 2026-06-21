// By xiplus
// Fake AC
/*
Input:
3
20 2
20 3
10 4
3
1 2 3

Correct Output:
20
20
10

Wrong output:
20
10
10
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
		s.insert(v[i].second);
	}
	sort(v.begin(), v.end());
	int q;
	cin >> q;
	vector<int> t(q), ti(q);
	for (int i = 0; i < q; i++) {
		cin >> t[i];
	}
	iota(ti.begin(), ti.end(), 0);
	sort(ti.begin(), ti.end(), [&](int a, int b) {
		return t[a] < t[b];
	});
	vector<int> ans(q);
	int ni = 0;
	for (int i = 0; i < q; i++) {
		while (ni < n && v[ni].first <= t[ti[i]]) {
			s.erase(v[ni].second);
			ni++;
		}
		ans[ti[i]] = *s.rbegin();
	}
	for (auto& v : ans) {
		cout << v << endl;
	}
}
