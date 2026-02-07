// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char s[3005][3005];
int vis[3005][3005], wall[3005], visIdx = 0;
void sol() {
	visIdx++;
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	for (int j = 1; j <= n; j++) {
		if (s[n][j] == '#') {
			wall[j] = visIdx;
		}
	}
	vis[n][c] = visIdx;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			if (vis[i + 1][j - 1] == visIdx || vis[i + 1][j] == visIdx || vis[i + 1][j + 1] == visIdx) {
				if (s[i][j] == '#') {
					if (wall[j] != visIdx) {
						vis[i][j] = visIdx;
						s[i][j] = '.';
					}
				} else {
					vis[i][j] = visIdx;
				}
			}
			if (s[i][j] == '#') {
				wall[j] = visIdx;
			}
		}
	}
	// cout << "vis " << visIdx << endl;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		if (vis[i][j] == visIdx) {
	// 			cout << 1;
	// 		} else {
	// 			cout << 0;
	// 		}
	// 	}
	// 	cout << endl;
	// }

	for (int j = 1; j <= n; j++) {
		if (vis[1][j] == visIdx) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
