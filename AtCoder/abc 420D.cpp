// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char a[2][505][505];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int aidx = 0;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<tuple<int, int, int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[0][i][j];
			if (a[0][i][j] == 'o') {
				a[1][i][j] = '#';
			} else if (a[0][i][j] == 'x') {
				a[0][i][j] = '#';
				a[1][i][j] = 'o';
			} else if (a[0][i][j] == 'S') {
				q.push({0, i, j, 0});
				a[0][i][j] = '#';
				a[1][i][j] = '.';
			} else {
				a[1][i][j] = a[0][i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		a[0][i][0] = '#';
		a[0][i][m + 1] = '#';
		a[1][i][0] = '#';
		a[1][i][m + 1] = '#';
	}
	for (int j = 1; j <= m; j++) {
		a[0][0][j] = '#';
		a[0][n + 1][j] = '#';
		a[1][0][j] = '#';
		a[1][n + 1][j] = '#';
	}
	while (!q.empty()) {
		auto [aidx, r, c, step] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int naidx = aidx;
			if (a[aidx][nr][nc] == '?') {
				naidx = 1 - aidx;
			}
			if (a[aidx][nr][nc] == '#') {
				continue;
			}
			if (a[aidx][nr][nc] == 'G') {
				cout << step + 1 << endl;
				return 0;
			}
			a[aidx][nr][nc] = '#';
			q.push({naidx, nr, nc, step + 1});
		}
	}
	cout << -1 << endl;
}
