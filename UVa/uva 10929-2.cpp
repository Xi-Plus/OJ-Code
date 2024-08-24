// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	while (cin >> s && s != "0") {
		int a = 0;
		for (int q = 0; q < s.size(); q++) {
			a *= 10;
			a += s[q] - '0';
			a %= 11;
		}
		if (a) {
			cout << s << " is not a multiple of 11." << endl;
		} else {
			cout << s << " is a multiple of 11." << endl;
		}
	}
}
