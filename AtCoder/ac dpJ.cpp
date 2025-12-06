// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
double dp[305][305][305];

double dfs(int i, int j, int k) {
	if (dp[i][j][k] >= 0) {
		return dp[i][j][k];
	}
	if (i == 0 && j == 0 && k == 0) {
		return 0;
	}
	double res = 0;
	if (i > 0) {
		res += dfs(i - 1, j, k) * i;
	}
	if (j > 0) {
		res += dfs(i + 1, j - 1, k) * j;
	}
	if (k > 0) {
		res += dfs(i, j + 1, k - 1) * k;
	}
	res += n;
	res /= (i + j + k);
	return dp[i][j][k] = res;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	fill_n(&dp[0][0][0], 305 * 305 * 305, -1);
	cin >> n;
	int a, cnt[4] = {};
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}
	cout << fixed << setprecision(20) << dfs(cnt[1], cnt[2], cnt[3]) << endl;
}
