// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	long long ans = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		int l = i, r = i + 1;
		if (s[l] + 1 == s[r]) {
			ans++;
			while (l > 0 && r < s.size() - 1 && s[l - 1] == s[l] && s[r + 1] == s[r]) {
				l--;
				r++;
				ans++;
			}
		}
	}
	cout << ans << endl;
}
