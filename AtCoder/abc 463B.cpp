// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	char c;
	cin >> n >> c;
	bool ans[5] = {};
	string s;
	while (n--) {
		cin >> s;
		for (int i = 0; i < 5; i++) {
			if (s[i] == 'o') {
				ans[i] = true;
			}
		}
	}
	cout << (ans[c - 'A'] ? "Yes" : "No") << endl;
}
