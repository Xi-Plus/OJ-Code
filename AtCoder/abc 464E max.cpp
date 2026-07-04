// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> m;
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, q;
	cin >> h >> w >> q;
	m.assign(h + 2, vector<int>(w + 2, -1));
	vector<int> r(q), c(q);
	vector<char> x(q);
	for (int i = 0; i < q; i++) {
		cin >> r[i] >> c[i] >> x[i];
		m[r[i]][c[i]] = i;
	}
	for (int i = h; i >= 1; i--) {
		for (int j = w; j >= 1; j--) {
			m[i][j] = max({m[i][j], m[i + 1][j], m[i][j + 1]});
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (m[i][j] == -1) {
				cout << 'A';
			} else {
				cout << x[m[i][j]];
			}
		}
		cout << endl;
	}
}
