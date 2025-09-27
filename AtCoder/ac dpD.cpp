// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, maxW;
	cin >> n >> maxW;
	int w, v;
	vector<long long> dp(maxW + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		for (int j = maxW; j >= w; j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[maxW] << endl;
}
