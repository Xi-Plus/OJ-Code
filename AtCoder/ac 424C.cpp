// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> edge[200005];
bool learn[200005];
bool visited[200005];
int ans = 0;
void dfs(int cur) {
	if (visited[cur]) {
		return;
	}
	ans++;
	visited[cur] = true;
	for (auto next : edge[cur]) {
		dfs(next);
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			learn[i] = true;
		} else {
			edge[a].push_back(i);
			edge[b].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (learn[i]) {
			dfs(i);
		}
	}
	cout << ans << endl;
}
