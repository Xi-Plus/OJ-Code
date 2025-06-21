// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int h, w;
int island[1002][1002];
queue<pair<int, int>> pending1;
queue<pair<int, int>> pending2;

void dfsStart(int r, int c) {
	if (island[r][c] == 1) {
		island[r][c] = 3;
		pending1.push({r, c});
		pending2.push({r, c});
	}
}

int ans = 2e9;
void update(int r, int c, int dis) {
	if (island[r][c] == 1) {
		ans = min(ans, -dis - 1);
	} else if (island[r][c] == 0) {
		island[r][c] = dis;
		pending2.push({r, c});
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	int startR, startC;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> island[i][j];
			if (island[i][j] == 1) {
				startR = i;
				startC = j;
			}
		}
	}
	for (int i = 1; i <= h; i++) {
		island[i][0] = 2;
		island[i][w + 1] = 2;
	}
	for (int i = 1; i <= w; i++) {
		island[0][i] = 2;
		island[h + 1][i] = 2;
	}

	pending1.push({startR, startC});
	island[startR][startC] = 3;
	pending2.push({startR, startC});
	while (!pending1.empty()) {
		auto cur = pending1.front();
		pending1.pop();
		dfsStart(cur.first + 1, cur.second);
		dfsStart(cur.first - 1, cur.second);
		dfsStart(cur.first, cur.second + 1);
		dfsStart(cur.first, cur.second - 1);
	}

	int dis;
	while (!pending2.empty()) {
		auto cur = pending2.front();
		pending2.pop();
		if (island[cur.first][cur.second] > 0) {
			dis = -1;
		} else {
			dis = island[cur.first][cur.second] - 1;
		}
		update(cur.first + 1, cur.second, dis);
		update(cur.first - 1, cur.second, dis);
		update(cur.first, cur.second + 1, dis);
		update(cur.first, cur.second - 1, dis);
	}
	if (ans == 2e9) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}
