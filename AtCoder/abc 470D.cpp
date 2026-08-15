// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> p(n + 1), pi(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pi[p[i]] = i;
	}
	int pending2 = 0, t, x, y;
	while (q--) {
		cin >> t;
		if (t == 1) {
			if (pending2) {
				if (pending2 % 2 == 1) {
					swap(p, pi);
				}
				pending2 = 0;
			}
			cin >> x >> y;
			swap(pi[p[x]], pi[p[y]]);
			swap(p[x], p[y]);
		} else {
			pending2++;
		}
	}
	if (pending2 % 2 == 1) {
		swap(p, pi);
	}
	pending2 = 0;
	for (int i = 1; i <= n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}
