// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int sz = 2005;
int cnt[sz][sz] = {}, label[sz][sz] = {};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int r1, r2, c1, c2;
	for (int i = 1; i <= n; i++) {
		cin >> r1 >> r2 >> c1 >> c2;
		cnt[r1][c1]++;
		cnt[r1][c2 + 1]--;
		cnt[r2 + 1][c1]--;
		cnt[r2 + 1][c2 + 1]++;
		label[r1][c1] += i;
		label[r1][c2 + 1] -= i;
		label[r2 + 1][c1] -= i;
		label[r2 + 1][c2 + 1] += i;
	}
	for (int r = 1; r < sz; r++) {
		for (int c = 1; c < sz; c++) {
			cnt[r][c] += cnt[r][c - 1];
			label[r][c] += label[r][c - 1];
		}
	}
	for (int r = 1; r < sz; r++) {
		for (int c = 1; c < sz; c++) {
			cnt[r][c] += cnt[r - 1][c];
			label[r][c] += label[r - 1][c];
		}
	}
	int ans[n + 1] = {};
	for (int r = 1; r <= 2000; r++) {
		for (int c = 1; c <= 2000; c++) {
			if (cnt[r][c] == 0) {
				ans[0]++;
			} else if (cnt[r][c] == 1) {
				ans[label[r][c]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[0] + ans[i] << endl;
	}
}
