// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Edge {
	int idx, time, price;
};

struct Node {
	int dis, price, idx;
	bool operator<(const Node& rhs) const {
		if (dis != rhs.dis) {
			return dis > rhs.dis;
		}
		return price > rhs.price;
	}
};

vector<Edge> G[1000005];
bool visited[1000005];

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, s, t;
	cin >> n >> s >> t;
	int a, b, time, price;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> time >> price;
		G[a].push_back({b, time, price});
		G[b].push_back({a, time, price});
	}
	priority_queue<Node> pq;
	pq.push({0, 0, s});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (visited[cur.idx]) {
			continue;
		}
		visited[cur.idx] = true;
		if (cur.idx == t) {
			cout << cur.dis << " " << cur.price;
			break;
		}
		for (auto& next : G[cur.idx]) {
			pq.push({cur.dis + next.time, cur.price + next.price, next.idx});
		}
	}

	priority_queue<Node> pq2;
	fill_n(visited, 1000005, false);
	pq2.push({0, 0, s});
	bool found = false;
	while (!pq2.empty()) {
		auto cur = pq2.top();
		pq2.pop();
		if (visited[cur.idx]) {
			continue;
		}
		visited[cur.idx] = true;
		if (cur.idx == t) {
			cout << " " << cur.dis << endl;
			found = true;
			break;
		}
		for (auto& next : G[cur.idx]) {
			if (next.price == 0) {
				pq2.push({cur.dis + next.time, cur.price + next.price, next.idx});
			}
		}
	}
	if (!found) {
		cout << " " << -1 << endl;
	}
}
