// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long MOD = 998244353;
long long ten[19] = {1};
void sol() {
	long long n, m;
	cin >> n >> m;
	long long ans = 0;
	for (int ydig = 1; ydig <= 18; ydig++) {
		long long xshift = ten[ydig] - 1;
		long long mm = m / __gcd(xshift, m);
		long long ycnt;
		if (n < ten[ydig] - 1) {
			ycnt = n - (ten[ydig - 1] - 1);
		} else {
			ycnt = ten[ydig] - ten[ydig - 1];
		}
		if (ycnt <= 0) {
			break;
		}
		ans += n / mm % MOD * (ycnt % MOD) % MOD;
		ans %= MOD;
		if (n < ten[ydig] - 1) {
			break;
		}
	}
	if (n == ten[18]) {
		unsigned long long xshift = 9999999999999999999ULL;
		long long mm = m / gcd(xshift, m);
		long long ycnt = 1;
		ans += n / mm % MOD * (ycnt % MOD) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i < 19; i++) {
		ten[i] = ten[i - 1] * 10;
	}
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
