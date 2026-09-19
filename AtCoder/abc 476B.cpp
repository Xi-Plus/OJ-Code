// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s, t;
	cin >> n >> s >> t;
	bool yes = true;
	for (int i = 0; i < n; i++) {
		if (t[i] != '*' && s[i] != t[i]) {
			yes = false;
		}
	}
	cout << (yes ? "Yes" : "No") << endl;
}
