// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long MOD = 998244353;
long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long m = power(a, b / 2);
	if (b & 1) {
		return m * m % MOD * a % MOD;
	} else {
		return m * m % MOD;
	}
}
long long inv(long long x) {
	return power(x, MOD - 2);
}
long long C(long long n, long long m) {
	if (n < 0 || m < 0 || n < m) {
		// cerr << n << " " << m << " " << 0 << endl;
		return 0;
	}
	long long ans = 1;
	for (long long i = 0; i < m; i++) {
		ans = ans * (n - i) % MOD;
		ans = ans * inv(i + 1) % MOD;
	}
	// cerr << n << " " << m << " " << ans << endl;
	return ans;
}

void answer() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	long long total = 0, sum_of_square = 0;
	for (auto& v : a) {
		cin >> v;
		total += v;
		sum_of_square += v * v % MOD;
		sum_of_square %= MOD;
	}
	total %= MOD;
	sum_of_square %= MOD;
	long long square_of_sum = total * total % MOD;

	long long ans = 0;
	if (n == 1) {
		ans += square_of_sum;
	} else {
		ans += square_of_sum * C(n - 2, k - 2) % MOD;
		ans += sum_of_square * C(n - 2, k - 1) % MOD;
	}
	ans %= MOD;
	cout << ans << endl;
}

void force() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	long long total = 0, t1 = 0;
	for (auto& v : a) {
		cin >> v;
		total += v;
		t1 += v * v;
	}
	cerr << total * total << " " << t1 << endl;
	string bitmask(k, 1);
	bitmask.resize(n, 0);

	long long ans = 0;
	do {
		long long total = 0;
		for (int i = 0; i < n; ++i) {
			if (bitmask[i]) {
				total += a[i];
			}
		}
		ans += total * total % MOD;
	} while (prev_permutation(bitmask.begin(), bitmask.end()));
	cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	answer();
	// force();
}
