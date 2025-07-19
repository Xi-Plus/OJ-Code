// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Point {
	int r, c, val;
};
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int cnt[3005][3005];
int ans[3005][3005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, k;
	cin >> h >> w >> k;
	queue<Point> q;
	int r, c;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		cnt[r][c] = 2;
		q.push({r, c, 0});
	}
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (nr < 1 || nr > h || nc < 1 || nc > w) {
				continue;
			}
			if (cnt[nr][nc] == 2) {
				continue;
			}
			cnt[nr][nc]++;
			if (cnt[nr][nc] == 2) {
				ans[nr][nc] = cur.val + 1;
				q.push({nr, nc, cur.val + 1});
			}
		}
	}
	long long total = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			total += ans[i][j];
		}
	}
	cout << total << endl;
}
