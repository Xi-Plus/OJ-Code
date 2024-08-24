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
			a %= 17;
		}
		cout << (a ? 0 : 1) << endl;
	}
}
