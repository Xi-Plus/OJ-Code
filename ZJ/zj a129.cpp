// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int parent[100005];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
struct Edge {
	int x, y, c;
	bool operator<(const Edge& rhs) const {
		return c < rhs.c;
	}
};
void kruskal() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		int px, py;
		int mergeCnt = 0;
		long long ans = 0;
		Edge edges[m];
		for (int i = 0; i < m; i++) {
			cin >> edges[i].x >> edges[i].y >> edges[i].c;
		}
		sort(edges, edges + m);
		for (int i = 0; i < m; i++) {
			px = find(edges[i].x);
			py = find(edges[i].y);
			if (px != py) {
				parent[py] = px;
				ans += edges[i].c;
				mergeCnt++;
			}
		}
		if (mergeCnt == n - 1) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
}

bool visited[100005];
struct Node {
	int idx, dis;
	bool operator<(const Node& rhs) const {
		return dis > rhs.dis;
	}
};
void prim() {
	int n, m;
	while (cin >> n >> m) {
		memset(visited, 0, sizeof(bool) * n);
		vector<pair<int, int>> edges[n];
		int x, y, c;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> c;
			if (x == y) {
				continue;
			}
			edges[x].push_back({y, c});
			edges[y].push_back({x, c});
		}
		long long ans = 0;
		priority_queue<Node> pq;
		pq.push({0, 0});
		int visitedCnt = 0;
		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			if (visited[cur.idx]) {
				continue;
			}
			visited[cur.idx] = true;
			visitedCnt++;
			ans += cur.dis;
			for (auto& [next, nextDis] : edges[cur.idx]) {
				if (!visited[next]) {
					pq.push({next, nextDis});
				}
			}
		}
		if (visitedCnt == n) {
			cout << ans << endl;
		} else {
			cout << -1 << endl;
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	kruskal();
	// prim();
}
