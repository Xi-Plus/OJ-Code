// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	if (s[0] == s[s.size() - 1]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
