// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char m[1005][1005];
int dist[1005][1005] = {};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<pair<int, int>> teleport[255];
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			cin >> m[r][c];
			if ('a' <= m[r][c] && m[r][c] <= 'z') {
				teleport[m[r][c]].push_back({r, c});
			}
		}
	}
	for (int r = 0; r <= h + 1; r++) {
		m[r][0] = '#';
		m[r][w + 1] = '#';
	}
	for (int c = 0; c <= w + 1; c++) {
		m[0][c] = '#';
		m[h + 1][c] = '#';
	}
	queue<pair<int, int>> q;
	q.push({1, 1});
	dist[1][1] = 1;
	while (!q.empty()) {
		auto [r, c] = q.front();
		if (r == h && c == w) {
			break;
		}
		q.pop();
		if ('a' <= m[r][c] && m[r][c] <= 'z') {
			for (auto [nr, nc] : teleport[m[r][c]]) {
				if (dist[nr][nc] == 0) {
					dist[nr][nc] = dist[r][c] + 1;
					q.push({nr, nc});
				}
			}
			teleport[m[r][c]].clear();
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (m[nr][nc] != '#' && dist[nr][nc] == 0) {
				dist[nr][nc] = dist[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}
	cout << dist[h][w] - 1 << endl;
}
