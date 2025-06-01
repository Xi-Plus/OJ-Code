// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool valid(string &s, int l, int r, bool extra) {
	while (l < r) {
		if (s[l] != s[r]) {
			if (extra) {
				return valid(s, l + 1, r, false) || valid(s, l, r - 1, false);
			} else {
				return false;
			}
		}
		l++;
		r--;
	}
	return true;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (valid(s, 0, s.size() - 1, true)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

/*
4
aaa
abc
abdbca
abba
*/
