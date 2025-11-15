// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int maxW = 0, ww;
	long long h, b;
	vector<int> w;
	vector<long long> v;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> ww >> h >> b;
		maxW += ww;
		ans += b;
		if (b < h) {
			w.push_back(ww);
			v.push_back(h - b);
		}
	}
	maxW /= 2;
	vector<long long> dp(maxW + 1);
	for (int i = 0; i < w.size(); i++) {
		for (int j = maxW; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	ans += dp[maxW];
	cout << ans << endl;
}
