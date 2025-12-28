// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == s.size() / 2) {
			continue;
		}
		cout << s[i];
	}
	cout << endl;
}
