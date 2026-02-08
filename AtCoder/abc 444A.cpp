// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	bool yes = true;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) {
			yes = false;
			break;
		}
	}
	if (yes) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
