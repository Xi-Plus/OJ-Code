// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> G[200005];
int a[200005];
bool ans[200005];
unordered_map<int, int> cnt;
void dfs(int cur, int from, bool curAns) {
	if (!curAns && cnt[a[cur]] > 0) {
		curAns = true;
	}
	cnt[a[cur]]++;
	ans[cur] = curAns;
	for (auto next : G[cur]) {
		if (next == from) {
			continue;
		}
		dfs(next, cur, curAns);
	}
	cnt[a[cur]]--;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0, false);
	for (int i = 1; i <= n; i++) {
		cout << (ans[i] ? "Yes" : "No") << endl;
	}
}
