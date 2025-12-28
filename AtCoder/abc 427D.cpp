// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t, n, m, k, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<char> ans(n + 1);
		vector<char> nans(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> ans[i];
		}
		vector<int> edges[n + 1];
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			edges[a].push_back(b);
		}
		while (k--) {
			for (int cur = 1; cur <= n; cur++) {
				bool found = false;
				for (auto& next : edges[cur]) {
					if (ans[next] == 'B') {
						found = true;
						break;
					}
				}
				if (found) {
					nans[cur] = 'B';
				} else {
					nans[cur] = 'A';
				}
			}
			swap(ans, nans);
			for (int cur = 1; cur <= n; cur++) {
				bool found = false;
				for (auto& next : edges[cur]) {
					if (ans[next] == 'A') {
						found = true;
						break;
					}
				}
				if (found) {
					nans[cur] = 'A';
				} else {
					nans[cur] = 'B';
				}
			}
			swap(ans, nans);
		}
		if (ans[1] == 'A') {
			cout << "Alice" << endl;
		} else {
			cout << "Bob" << endl;
		}
	}
}
