// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int l, r;
	set<int> ss;
	while (m--) {
		cin >> l >> r;
		if (ss.count(l - 1)) {
			ss.erase(l - 1);
		} else {
			ss.insert(l - 1);
		}
		if (ss.count(r)) {
			ss.erase(r);
		} else {
			ss.insert(r);
		}
	}
	vector<int> v(ss.begin(), ss.end());
	v.push_back(n);
	bool first = true;
	int i = 0, vi = 0;
	while (i < n) {
		while (i < v[vi] && i < n) {
			if (first) {
				cout << s[i];
			} else {
				cout << t[i];
			}
			i++;
		}
		first = !first;
		vi++;
	}
}
