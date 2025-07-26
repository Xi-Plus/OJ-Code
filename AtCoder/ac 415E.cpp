// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	long long v[h][w], ans[h][w];
	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			cin >> v[r][c];
		}
	}
	long long cost[h + w - 1];
	for (int i = 0; i < h + w - 1; i++) {
		cin >> cost[i];
	}
	ans[h - 1][w - 1] = cost[h + w - 2] - v[h - 1][w - 1];
	ans[h - 1][w - 1] = max(ans[h - 1][w - 1], 0LL);
	for (int c = w - 2; c >= 0; c--) {
		ans[h - 1][c] = ans[h - 1][c + 1] + cost[h - 1 + c] - v[h - 1][c];
		ans[h - 1][c] = max(ans[h - 1][c], 0LL);
	}
	for (int r = h - 2; r >= 0; r--) {
		ans[r][w - 1] = ans[r + 1][w - 1] + cost[r + w - 1] - v[r][w - 1];
		ans[r][w - 1] = max(ans[r][w - 1], 0LL);
		for (int c = w - 2; c >= 0; c--) {
			ans[r][c] = min(ans[r][c + 1], ans[r + 1][c]) + cost[r + c] - v[r][c];
			ans[r][c] = max(ans[r][c], 0LL);
		}
	}
	// for (int r = 0; r < h; r++) {
	// 	for (int c = 0; c < w; c++) {
	// 		cout << ans[r][c] << " ";
	// 	}
	// 	cout << endl;
	// }
	if (ans[0][0] < 0) {
		cout << 0 << endl;
	} else {
		cout << ans[0][0] << endl;
	}
}
