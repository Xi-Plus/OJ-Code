// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct MyHash {
	size_t operator()(const pair<int, int>& p) const {
		return (((size_t)p.first) << 32) | p.second;
	}
};

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	int a[h + 2][w + 2] = {};
	unordered_set<pair<int, int>, MyHash> nextpoint, newcheck;
	int nr, nc;
	for (int r = 0; r <= h + 1; r++) {
		a[r][0] = a[r][w + 1] = -100;
	}
	for (int c = 0; c <= w + 1; c++) {
		a[0][c] = a[h + 1][c] = -100;
	}
	int ans = 0;
	char ch;
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			cin >> ch;
			if (ch == '#') {
				ans++;
				a[r][c] = 1;
				for (int d = 0; d < 4; d++) {
					nr = r + dr[d];
					nc = c + dc[d];
					if (a[nr][nc] == 0) {
						newcheck.insert({nr, nc});
					}
				}
			}
		}
	}
	int cnt;
	while (newcheck.size() > 0) {
		nextpoint.clear();
		for (auto& p : newcheck) {
			if (a[p.first][p.second] != 0) {
				continue;
			}
			cnt = 0;
			for (int d = 0; d < 4; d++) {
				nr = p.first + dr[d];
				nc = p.second + dc[d];
				if (a[nr][nc] == 1) {
					cnt++;
				}
			}
			if (cnt == 1) {
				nextpoint.insert(p);
			}
		}
		newcheck.clear();
		for (auto& p : nextpoint) {
			a[p.first][p.second] = 1;
			ans++;
		}
		for (auto& p : nextpoint) {
			for (int d = 0; d < 4; d++) {
				nr = p.first + dr[d];
				nc = p.second + dc[d];
				if (a[nr][nc] == 0) {
					newcheck.insert({nr, nc});
				}
			}
		}
	}
	cout << ans << endl;
}
