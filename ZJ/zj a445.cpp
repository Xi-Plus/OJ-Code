// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int parent[10001] = {};
int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		cin >> a >> b;
		parent[findParent(a)] = findParent(b);
	}
	while (q--) {
		cin >> a >> b;
		if (findParent(a) == findParent(b)) {
			cout << ":)" << endl;
		} else {
			cout << ":(" << endl;
		}
	}
}
/*
5 3 2
1 2
2 5
3 4
1 5
1 3
*/
