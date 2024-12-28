// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> edges[2001];
bool visited[2001] = {};
bool cycle = false;
void dfs(int src, int cur) {
	for (auto next : edges[cur]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(cur, next);
		} else {
			if (next != src) {
				cycle = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			cycle = false;
			dfs(-1, i);
			if (cycle) {
				ans1++;
			} else {
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2 << endl;
}
/*
7 6
0 1
1 2
2 0
1 3
4 5
5 6

6 6
0 1
1 2
2 0
3 4
4 5
5 3

2 1
0 1

12 10
2 1
2 3
1 0
0 4
8 10
10 7
7 11
9 10
6 8
5 7
*/
