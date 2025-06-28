// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int edgeCnt;

unordered_set<int> nei[300005];
pair<int, int> edges[300005];
int parent[300005];
int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}
void merge(int a, int b) {
	int pa = findParent(a);
	int pb = findParent(b);
	if (pa != pb) {
		parent[pa] = pb;
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	edgeCnt = m;
	int a, b;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		edges[i] = {a, b};
		nei[a].insert(b);
		nei[b].insert(a);
	}
	int q;
	cin >> q;
	while (q--) {
		cin >> a;
		int pa = findParent(edges[a].first);
		int pb = findParent(edges[a].second);
		if (pa != pb) {
			edgeCnt--;
			for (auto &neighbor : nei[pa]) {
				if (nei[pb].find(neighbor) != nei[pb].end() && findParent(neighbor) != pa && findParent(neighbor) != pb) {
					// cout << "remove " << pa << " " << pb << " " << neighbor << endl;
					edgeCnt--;
				}
			}
			for (auto &neighbor : nei[pa]) {
				nei[pb].insert(neighbor);
			}
			merge(pa, pb);
		}
		cout << edgeCnt << endl;
	}
}
