// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[10][10];
int ansmin;
int h, w;
void dfs(int r, int c, int ans) {
	if (r > h) {
		ansmin = min(ansmin, ans);
		return;
	}
	if (c > w) {
		dfs(r + 1, 1, ans);
		return;
	}
	if (a[r][c] == 4) {
		a[r][c - 1]--;
		a[r][c]--;
		a[r + 1][c - 1]--;
		a[r + 1][c]--;
		dfs(r, c + 1, ans + 1);
		a[r][c - 1]++;
		a[r][c]++;
		a[r + 1][c - 1]++;
		a[r + 1][c]++;

		a[r][c]--;
		a[r][c + 1]--;
		a[r + 1][c]--;
		a[r + 1][c + 1]--;
		dfs(r, c + 1, ans + 1);
		a[r][c]++;
		a[r][c + 1]++;
		a[r + 1][c]++;
		a[r + 1][c + 1]++;
	} else {
		dfs(r, c + 1, ans);
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	char ch;
	while (t--) {
		cin >> h >> w;
		memset(a, 0, sizeof(a));
		for (int r = 1; r <= h; r++) {
			for (int c = 1; c <= w; c++) {
				cin >> ch;
				if (ch == '#') {
					a[r][c]++;
					a[r + 1][c]++;
					a[r][c + 1]++;
					a[r + 1][c + 1]++;
				}
			}
		}
		ansmin = 1e9;
		dfs(1, 1, 0);
		cout << ansmin << endl;
	}
}
