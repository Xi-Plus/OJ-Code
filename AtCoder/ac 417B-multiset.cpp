// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	multiset<int> s;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		auto pos = s.find(x);
		if (pos != s.end()) {
			s.erase(pos);
		}
	}
	for (auto it : s) {
		cout << it << ' ';
	}
	return 0;
}
