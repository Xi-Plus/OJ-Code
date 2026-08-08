// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<int> a, b;
set<pair<int, int>> ans;
void check(int v) {
	int j, p1, p2;
	for (j = 1; j < m; j++) {
		if (a[j] != v && b[j] != v) {
			p1 = a[j];
			p2 = b[j];
			break;
		}
	}
	if (j == m) {
		for (int i = 1; i <= n; i++) {
			if (i != v) {
				ans.insert({
					min(v, i),
					max(v, i),
				});
			}
		}
	} else {
		for (; j < m; j++) {
			if (a[j] == v || b[j] == v) {
				continue;
			}
			if (p1 != a[j] && p1 != b[j]) {
				p1 = -1;
			}
			if (p2 != a[j] && p2 != b[j]) {
				p2 = -1;
			}
		}
		if (p1 != -1) {
			ans.insert({
				min(v, p1),
				max(v, p1),
			});
		}
		if (p2 != -1) {
			ans.insert({
				min(v, p2),
				max(v, p2),
			});
		}
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	a.resize(m);
	b.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	check(a[0]);
	check(b[0]);
	cout << ans.size() << endl;
}
