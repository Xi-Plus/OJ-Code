// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	string s;
	int n;
	while (t--) {
		cin >> n >> s;
		char ch = s[0];
		int maxlen[2] = {}, len = 0;
		int cnt[2] = {};
		for (auto& c : s) {
			if (c == ch) {
				len++;
			} else {
				if (ch == '0' && len > maxlen[0]) {
					maxlen[0] = len;
				} else if (ch == '1' && len > maxlen[1]) {
					maxlen[1] = len;
				}
				ch = c;
				len = 1;
			}
			cnt[c - '0']++;
		}
		if (ch == '0' && len > maxlen[0]) {
			maxlen[0] = len;
		} else if (ch == '1' && len > maxlen[1]) {
			maxlen[1] = len;
		}
		cout << min(cnt[1] + (cnt[0] - maxlen[0]) * 2, cnt[0] + (cnt[1] - maxlen[1]) * 2) << endl;
	}
}
