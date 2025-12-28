// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool check_base(long long n, int b) {
	string s = "";
	while (n) {
		s += (n % b + '0');
		n /= b;
	}
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l++] != s[r--]) {
			return false;
		}
	}
	return true;
}
vector<long long> ten;
long long mirror(long long n, int dig) {
	long long ans = n;
	for (int i = 0; i < dig / 2; i++) {
		ans += ten[dig - i - 1] * (n % 10);
		n /= 10;
	}
	return ans;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long t = 1;
	for (int i = 0; i < 18; i++) {
		ten.push_back(t);
		t *= 10;
	}
	int a;
	long long n, ans = 0, real;
	cin >> a >> n;
	for (int dig = 1; dig <= 12; dig++) {
		for (int low = 1; low < ten[(dig + 1) / 2]; low++) {
			real = mirror(low, dig);
			if (real % 10 == 0) {
				continue;
			}
			if (real <= n && check_base(real, a)) {
				ans += real;
			}
		}
	}
	cout << ans << endl;
}
