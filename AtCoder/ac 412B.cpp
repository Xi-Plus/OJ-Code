// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s, t;
	bool ans = true;
	unordered_set<char> tchar;
	cin >> s >> t;
	for (auto c : t) {
		tchar.insert(c);
	}
	for (int i = 1; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			if (tchar.find(s[i - 1]) == tchar.end()) {
				ans = false;
				break;
			}
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
