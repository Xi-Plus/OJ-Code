// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
struct Edge {
	int idx, next;
};
vector<Edge> edges[200005];
int treesize[200005];
long long ans[200005];
long long total = 0;

int dfs1(int cur, int par) {
	int sz = 1;
	for (auto& nei : edges[cur]) {
		if (nei.next != par) {
			sz += dfs1(nei.next, cur);
		}
	}
	treesize[cur] = sz;
	return sz;
}
void dfs2(int cur, int par, long long sum) {
	ans[cur] += sum;
	for (auto& nei : edges[cur]) {
		if (nei.next != par) {
			if (treesize[nei.next] <= n / 2) {
				total += nei.idx;
				dfs2(nei.next, cur, sum - nei.idx);
			} else {
				dfs2(nei.next, cur, sum + nei.idx);
			}
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int a, b;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a >> b;
		edges[a].push_back({i, b});
		edges[b].push_back({i, a});
	}
	dfs1(1, -1);
	dfs2(1, -1, 0);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] + total << " ";
	}
	cout << endl;
}
