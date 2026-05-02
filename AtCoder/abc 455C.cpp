// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> cnt;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}
	vector<long long> b;
	for (auto [v, c] : cnt) {
		b.push_back((long long)v * c);
	}
	sort(b.begin(), b.end());
	long long ans = 0;
	for (int i = 0; i < (int)b.size() - k; i++) {
		ans += b[i];
	}
	cout << ans << endl;
}
