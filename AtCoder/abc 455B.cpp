// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char a[15][15];

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int l = 1; l <= w; l++) {
		for (int r = l; r <= w; r++) {
			for (int u = 1; u <= h; u++) {
				for (int d = u; d <= h; d++) {
					bool ok = true;
					for (int ll = l; ll <= r; ll++) {
						for (int uu = u; uu <= d; uu++) {
							if (a[uu][ll] != a[u + d - uu][l + r - ll]) {
								ok = false;
								break;
							}
						}
					}
					if (ok) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
