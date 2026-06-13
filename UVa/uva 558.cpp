// By xiplus
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
struct Edge {
	int u, v, w;
};
void sol() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edge(m);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	vector<int> dis(n, 1e9);
	dis[0] = 0;
	bool updated;
	for (int i = 0; i < n; i++) {
		updated = false;
		for (auto& [u, v, w] : edge) {
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				updated = true;
			}
		}
	}
	cout << (updated ? "possible" : "not possible") << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
