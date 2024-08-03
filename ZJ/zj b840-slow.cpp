// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		int v[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		int ans = v[0][0];
		for (int t = 0; t < n; t++) {
			for (int l = 0; l < n; l++) {
				for (int b = t; b < n; b++) {
					for (int r = l; r < n; r++) {
						int cur = 0;
						for (int i = l; i <= r; i++) {
							for (int j = t; j <= b; j++) {
								cur += v[i][j];
							}
						}
						ans = max(ans, cur);
					}
				}
			}
		}
		cout << ans << endl;
	}
}
