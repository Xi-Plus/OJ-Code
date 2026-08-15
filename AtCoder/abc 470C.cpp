// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int a[n + 1] = {};
	int t, x, ans = 0;
	set<int> s;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			ans ^= a[x];
			a[x]++;
			ans ^= a[x];
			if (a[x] == 1) {
				s.insert(x);
			}
		} else {
			for (auto it = s.begin(); it != s.end();) {
				int v = *it;
				ans ^= a[v];
				a[v]--;
				ans ^= a[v];
				if (a[v] == 0) {
					s.erase(it++);
				} else {
					it++;
				}
			}
		}
		cout << ans << endl;
	}
}
