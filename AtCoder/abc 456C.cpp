// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long MOD = 998244353;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	long long ans = 1;
	int l = 0;
	for (int r = 1; r < s.size(); r++) {
		if (s[r] == s[r - 1]) {
			l = r;
		}
		ans += r - l + 1;
	}
	cout << ans % MOD << endl;
}
