// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dig(int n) {
	int ans = 0;
	while (n) {
		ans++;
		n /= 10;
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	unordered_map<int, int> cnt[11];
	long long pow10;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pow10 = 10;
		for (int j = 1; j <= 10; j++) {
			cnt[j][pow10 % m * a[i] % m]++;
			pow10 *= 10;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += cnt[dig(a[i])][(m - a[i] % m) % m];
	}
	cout << ans << endl;
}
