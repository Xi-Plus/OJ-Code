// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Next {
	int v, type;
};
vector<Next> G[200005];
struct Query {
	int type, u, v;
};
int visitid = 0;
int visited[200005];
vector<int> ans;
bool good = true;
int n;
void dfs(int cur) {
	if (!good) {
		return;
	}
	for (auto [v, type] : G[cur]) {
		if (type == 0) {
			// cerr << "check 0 " << ans[cur] << " " << ans[v] << endl;
			if (!(ans[cur] <= ans[v])) {
				if (visited[v] > visitid + 5) {
					good = false;
					return;
				}
				ans[v] = ans[cur];
				// cerr << "fix " << v << " to " << ans[v] << endl;
				visited[v] = max(visited[v] + 1, visitid);
				dfs(v);
			}
		} else {
			// cerr << "check 1 " << ans[cur] << " " << ans[v] << endl;
			if (!(ans[cur] < ans[v])) {
				if (visited[v] > visitid + 5) {
					good = false;
					return;
				}
				ans[v] = ans[cur] + 1;
				if (ans[v] > n) {
					good = false;
				}
				// cerr << "fix " << v << " to " << ans[v] << endl;
				visited[v] = max(visited[v] + 1, visitid);
				dfs(v);
			}
		}
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> n >> q;
	int type, u, v;
	// vector<Query> query(q);
	for (int i = 0; i < q; i++) {
		cin >> type >> u >> v;
		G[u].push_back({v, type});
	}
	ans.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		visitid += 10;
		dfs(i);
	}
	if (good) {
		cout << "Yes" << endl;
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		// for (int i = 1; i <= n; i++) {
		// 	cerr << i << " " << ans[i] << endl;
		// }
	} else {
		cout << "No" << endl;
	}
}
