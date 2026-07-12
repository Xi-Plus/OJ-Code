// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int sz[m + 1] = {};
	int c, s;
	for (int i = 0; i < n; i++) {
		cin >> c >> s;
		sz[c] = max(sz[c], s);
	}
	for (int i = 1; i <= m; i++) {
		if (sz[i] == 0) {
			cout << -1 << " ";
		} else {
			cout << sz[i] << " ";
		}
	}
	cout << endl;
}
