// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char v[1005][1005];
int ans = 0;
void dfs(int r, int c) {
	if (v[r][c] == '#') {
		return;
	}
	v[r][c] = '#';
	dfs(r - 1, c);
	dfs(r + 1, c);
	dfs(r, c - 1);
	dfs(r, c + 1);
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	for (int r = 0; r <= h + 1; r++) {
		v[r][0] = v[r][w + 1] = '#';
	}
	for (int c = 0; c <= w + 1; c++) {
		v[0][c] = v[h + 1][c] = '#';
	}

	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			cin >> v[r][c];
		}
	}

	for (int r = 1; r <= h; r++) {
		if (v[r][1] == '.') {
			dfs(r, 1);
		}
		if (v[r][w] == '.') {
			dfs(r, w);
		}
	}
	for (int c = 1; c <= w; c++) {
		if (v[1][c] == '.') {
			dfs(1, c);
		}
		if (v[h][c] == '.') {
			dfs(h, c);
		}
	}
	for (int r = 2; r < h; r++) {
		for (int c = 2; c < w; c++) {
			if (v[r][c] == '.') {
				ans++;
				dfs(r, c);
			}
		}
	}
	cout << ans << endl;
}
