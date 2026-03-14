// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int parent[200005];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
vector<int> toRemove;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int u[m], v[m];
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
	}
	iota(parent + 1, parent + 1 + n, 1);
	int pa, pb;
	int deg = n;
	for (int i = m - 1; i >= 0; i--) {
		pa = find(u[i]);
		pb = find(v[i]);
		if (pa != pb) {
			if (deg == 2) {
				toRemove.push_back(i + 1);
			} else {
				parent[pa] = pb;
				deg--;
			}
		}
	}
	long long ans = 0;
	const long long MOD = 998244353;
	long long t = 1, p = 0;
	reverse(toRemove.begin(), toRemove.end());
	for (auto v : toRemove) {
		while (p < v) {
			p++;
			t = (t * 2) % MOD;
		}
		ans += t;
		ans %= MOD;
	}
	cout << ans << endl;
}
