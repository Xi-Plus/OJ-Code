// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool notP[10000005] = {};
string s;
bool check(int x) {
	string t = to_string(x);
	if (t.size() != s.size()) {
		return false;
	}
	for (int i = 0; i < t.size(); i++) {
		for (int j = 1; j < s.size(); j++) {
			if (s[i] == s[j]) {
				if (t[i] != t[j]) {
					return false;
				}
			} else {
				if (t[i] == t[j]) {
					return false;
				}
			}
		}
	}
	return true;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for (int i = 2; i <= 9999999; i++) {
		if (!notP[i]) {
			if (check(i)) {
				cout << i << endl;
				return 0;
			}
			for (int j = i * 2; j <= 9999999; j += i) {
				notP[j] = true;
			}
		}
	}
	cout << -1 << endl;
}
