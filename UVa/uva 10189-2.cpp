// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	char c;
	for (int t = 1;; t++) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		int map[n + 2][m + 2] = {};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c;
				if (c == '*') {
					map[i][j] = -10;
					for (int di = -1; di <= 1; di++) {
						for (int dj = -1; dj <= 1; dj++) {
							map[i + di][j + dj] += 1;
						}
					}
				}
			}
		}
		if (t >= 2) {
			cout << endl;
		}
		cout << "Field #" << t << ":" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] < 0) {
					cout << '*';
				} else {
					cout << map[i][j];
				}
			}
			cout << endl;
		}
	}
}
/*
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
*/
