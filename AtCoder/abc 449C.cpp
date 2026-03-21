// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	string s;
	cin >> s;
	unordered_map<char, int> cnt;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (i - l >= 0) {
			cnt[s[i - l]]++;
			// cout << "add " << s[i - l] << endl;
		}
		// cout << i << " " << s[i] << " " << cnt[s[i]] << endl;
		ans += cnt[s[i]];
		if (i - r >= 0) {
			cnt[s[i - r]]--;
			// cout << "remove " << s[i - r] << endl;
		}
	}
	cout << ans << endl;
}
