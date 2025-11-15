// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, maxW;
	cin >> n >> maxW;
	vector<long long> w(n);
	vector<int> v(n);
	int maxV = 0;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		maxV += v[i];
	}
	vector<long long> dp(maxV + 1, 1LL << 62);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = maxV; j >= v[i]; j--) {
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	for (int i = maxV; i >= 0; i--) {
		if (dp[i] <= maxW) {
			cout << i << endl;
			break;
		}
	}
}
