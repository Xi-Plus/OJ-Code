// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int parent[200005];
int blackcnt[200005];
bool isblack[200005];
int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}
void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
		parent[b] = a;
		blackcnt[a] += blackcnt[b];
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int t, u, v, pu, pv;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> u >> v;
			merge(u, v);
		} else if (t == 2) {
			cin >> v;
			if (isblack[v]) {
				isblack[v] = false;
				blackcnt[findParent(v)]--;
			} else {
				isblack[v] = true;
				blackcnt[findParent(v)]++;
			}
		} else {
			cin >> v;
			if (blackcnt[findParent(v)] > 0) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}
}
