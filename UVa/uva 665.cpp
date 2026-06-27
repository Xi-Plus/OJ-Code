// By xiplus
#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<vector<int>> l, r;
vector<char> c;

int n, m;
bool in(int x, vector<int>& v) {
	return find(v.begin(), v.end(), x) != v.end();
}
bool check(int x) {
	int light = 0, heavy = 0;
	for (int i = 0; i < m; i++) {
		if (c[i] == '=') {
			if (!in(x, l[i]) && !in(x, r[i])) {
				light++;
				heavy++;
			}
		} else if (c[i] == '<') {
			if (in(x, l[i]))
				light++;
			else if (in(x, r[i]))
				heavy++;
		} else {
			if (in(x, l[i]))
				heavy++;
			else if (in(x, r[i]))
				light++;
		}
	}
	return light == m || heavy == m;
}

void sol() {
	cin >> n >> m;
	l.clear();
	r.clear();
	c.clear();
	l.resize(m);
	r.resize(m);
	c.resize(m);
	int p;
	for (int i = 0; i < m; i++) {
		cin >> p;
		l[i].resize(p);
		r[i].resize(p);
		for (int j = 0; j < p; j++) cin >> l[i][j];
		for (int j = 0; j < p; j++) cin >> r[i][j];
		cin >> c[i];
	}
	int ans, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check(i)) {
			ans = i;
			cnt++;
		}
	}
	if (cnt == 1)
		cout << ans << endl;
	else
		cout << 0 << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
		if (t) cout << endl;
	}

	while(scanf("%d%d", &n, &m) != EOF) {
		sol();
	}
}
