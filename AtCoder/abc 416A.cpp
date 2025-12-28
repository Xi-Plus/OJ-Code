// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, l, r;
	string s;
	cin >> n >> l >> r;
	cin >> s;
	bool ans = true;
	for (int i = l - 1; i < r; i++) {
		if (s[i] != 'o') {
			ans = false;
			break;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
