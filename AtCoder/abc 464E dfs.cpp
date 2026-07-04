// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<char>> m;
const char EMPTY = '?', WALL = '#';
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int nr, nc;
void dfs(int r, int c, char t) {
	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (m[nr][nc] == EMPTY) {
			m[nr][nc] = t;
			dfs(nr, nc, t);
		}
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, q;
	cin >> h >> w >> q;
	m.assign(h + 2, vector<char>(w + 2, EMPTY));
	for (int i = 0; i <= h; i++) {
		m[i][0] = WALL;
		m[i][w + 1] = WALL;
	}
	for (int i = 0; i <= w; i++) {
		m[0][i] = WALL;
		m[h + 1][i] = WALL;
	}
	vector<int> r(q), c(q);
	vector<char> x(q);
	for (int i = 0; i < q; i++) {
		cin >> r[i] >> c[i] >> x[i];
	}
	for (int i = q - 1; i >= 0; i--) {
		if (m[r[i]][c[i]] == EMPTY) {
			m[r[i]][c[i]] = x[i];
			for (int j = r[i] - 1; j >= 1; j--) {
				if (m[j][c[i]] == EMPTY) {
					m[j][c[i]] = x[i];
				} else {
					break;
				}
			}
			for (int j = c[i] - 1; j >= 1; j--) {
				if (m[r[i]][j] == EMPTY) {
					m[r[i]][j] = x[i];
				} else {
					break;
				}
			}
			if (m[r[i] - 1][c[i] - 1] == EMPTY) {
				m[r[i] - 1][c[i] - 1] = x[i];
				dfs(r[i] - 1, c[i] - 1, x[i]);
			}
		}
	}
	if (m[h][w] == EMPTY) {
		m[h][w] = 'A';
		dfs(h, w, 'A');
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << m[i][j];
		}
		cout << endl;
	}
}
