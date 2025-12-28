// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int x, n;
	cin >> x >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	unordered_set<int> s;
	int q, p;
	cin >> q;
	while (q--) {
		cin >> p;
		if (s.count(p)) {
			x -= w[p - 1];
			s.erase(p);
		} else {
			x += w[p - 1];
			s.insert(p);
		}
		cout << x << endl;
	}
}
