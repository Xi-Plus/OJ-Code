// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long mod = 998244353;
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long n;
	cin >> n;
	long long ans = 0;
	long long k = (long long)sqrt(n);
	long long temp = 0;
	for (long long i = 1; i <= k; i++) {
		temp += (n / i) * 2;
		temp %= mod;
	}
	long long nn;
	if (n % 2 == 0) {
		nn = n / 2 % mod * ((n + 1) % mod) % mod;
	} else {
		nn = (n + 1) / 2 % mod * (n % mod) % mod;
	}
	temp = (temp - k % mod * k % mod) % mod;
	temp = (temp + mod) % mod;
	ans = ((n % mod) * (n % mod) % mod - temp - nn + n % mod) % mod;
	ans = (ans + mod) % mod;
	cout << ans << endl;
}
