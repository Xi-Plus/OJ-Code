// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, maxW;
	cin >> n >> maxW;
	int w, v;
	vector<long long> dp(maxW + 1, 0), prev(maxW + 1, 0);
	for (int i = 0; i < n; i++) {
		swap(dp, prev);
		cin >> w >> v;
		for (int j = 0; j < w; j++) {
			dp[j] = prev[j];
		}
		for (int j = w; j <= maxW; j++) {
			dp[j] = max(prev[j], prev[j - w] + v);
		}
	}
	cout << dp[maxW] << endl;
}
