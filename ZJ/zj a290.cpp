// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b, cur;
	while (cin >> n >> m) {
		unordered_set<int> edges[n + 1];
		while (m--) {
			cin >> a >> b;
			if (a != b) {
				edges[a].insert(b);
			}
		}
		cin >> a >> b;
		queue<int> q;
		q.push(a);
		bool vis[n + 1] = {};
		vis[a] = true;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur == b) {
				break;
			}
			for (auto next : edges[cur]) {
				if (!vis[next]) {
					q.push(next);
					vis[next] = true;
				}
			}
		}
		if (vis[b]) {
			cout << "Yes!!!" << endl;
		} else {
			cout << "No!!!" << endl;
		}
	}
}
/*
8 32
7 4
2 5
7 5
3 7
2 1
2 2
2 4
4 4
4 7
8 5
7 5
5 2
6 7
7 5
8 8
4 7
6 3
4 1
4 4
8 7
3 4
2 6
6 1
6 8
4 5
7 5
6 6
4 4
2 6
5 3
7 4
1 3
1 3
*/
