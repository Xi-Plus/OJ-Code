// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int h, w;
char g[1005][1005];
bool vis[1005][1005];
bool vis2[1005][1005][4];
vector<int> source[1005][1005];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
char dirname[] = {'D', 'U', 'R', 'L'};
int gr, gc;
bool found = false;
queue<pair<int, int>> q;
vector<int> path;
void dfs(int r, int c, int srcdir) {
	if (g[r][c] == 'G') {
		source[r][c] = path;
		gr = r;
		gc = c;
		found = true;
		return;
	}
	if (g[r][c] == '#') {
		return;
	}
	if (g[r][c] == '.') {
		if (vis[r][c]) {
			return;
		} else {
			vis[r][c] = true;
			source[r][c] = path;
			q.push({r, c});
			return;
		}
	}
	if (g[r][c] == 'o') {
		if (vis2[r][c][srcdir]) {
			return;
		} else {
			vis2[r][c][srcdir] = true;
			path.push_back(srcdir);
			dfs(r + dr[srcdir], c + dc[srcdir], srcdir);
			path.pop_back();
		}
		return;
	}
	if (g[r][c] == 'x') {
		if (vis2[r][c][srcdir]) {
			return;
		} else {
			vis2[r][c][srcdir] = true;
			for (int dir = 0; dir < 4; dir++) {
				if (dir == srcdir) {
					continue;
				}
				path.push_back(dir);
				dfs(r + dr[dir], c + dc[dir], dir);
				path.pop_back();
			}
			return;
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	int sr, sc;
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			cin >> g[r][c];
			if (g[r][c] == 'S') {
				q.push({r, c});
				sr = r;
				sc = c;
				vis[r][c] = true;
			}
		}
	}
	for (int r = 0; r <= h + 1; r++) {
		g[r][0] = g[r][w + 1] = '#';
	}
	for (int c = 0; c <= w + 1; c++) {
		g[0][c] = g[h + 1][c] = '#';
	}
	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			path.push_back(dir);
			dfs(nr, nc, dir);
			path.pop_back();
		}
	}
	if (found) {
		int r = gr, c = gc;
		cout << "Yes" << endl;
		vector<int> ans;
		while (r != sr || c != sc) {
			int nr = r, nc = c;
			for (int i = source[r][c].size() - 1; i >= 0; i--) {
				ans.push_back(source[r][c][i]);
				nr -= dr[source[r][c][i]];
				nc -= dc[source[r][c][i]];
			}
			r = nr;
			c = nc;
		}
		reverse(ans.begin(), ans.end());
		for (auto dir : ans) {
			cout << dirname[dir];
		}
		cout << endl;
	} else {
		cout << "No" << endl;
	}
}
