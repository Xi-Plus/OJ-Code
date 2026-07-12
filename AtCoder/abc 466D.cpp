// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cr[n + 1] = {};
	int cc[n + 1] = {};
	int r, c;
	for (int i = 1; i <= m; i++) {
		cin >> r >> c;
		cr[r] = i;
		cc[c] = i;
	}
	int ct[m + 1] = {};
	for (int i = 1; i <= n; i++) {
		ct[cr[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ct[cc[i]]++;
		if (ct[cc[i]] == 2 && cc[i] != 0) {
			ans++;
		}
	}
	cout << ans << endl;
}
