// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
	int n, w;
	cin >> n >> w;
	int w2 = w * 2;
	long long sumc[w2 * 2] = {}, x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sumc[i % w2] += x;
	}
	for (int i = 0; i < w2; i++) {
		sumc[i + w2] = sumc[i];
	}
	long long cur = 0;
	for (int i = 0; i < w; i++) {
		cur += sumc[i];
	}
	long long ans = cur;
	for (int i = 0; i < w2; i++) {
		cur -= sumc[i];
		cur += sumc[i + w];
		ans = min(ans, cur);
	}
	cout << ans << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
