// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	char dirname[4] = {'N', 'E', 'S', 'W'};
	while (t--) {
		int h, w;
		cin >> h >> w;
		cin.ignore();
		int map[h][w] = {};
		string s;
		for (int i = 0; i < h; i++) {
			getline(cin, s);
			for (int j = 0; j < w; j++) {
				if (s[j] == '*') {
					map[i][j] = 1;
				}
			}
		}
		int x, y, nx, ny, dir = 0;
		cin >> x >> y;
		x--;
		y--;
		char c;
		while (cin >> c && c != 'Q') {
			if (c == 'R') {
				dir = (dir + 1) % 4;
			} else if (c == 'L') {
				dir = (dir - 1 + 4) % 4;
			} else if (c == 'F') {
				nx = x + dx[dir];
				ny = y + dy[dir];
				if (map[nx][ny] == 0) {
					x = nx;
					y = ny;
				}
			}
		}
		cout << x + 1 << " " << y + 1 << " " << dirname[dir] << endl;
		if (t > 0) {
			cout << endl;
		}
	}
}
/*
1
7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ
*/
