#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, q, l, r;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		cin >> q;
		while (q--) {
			cin >> l >> r;
			for (int i = l; i <= r; i++) {
				cout << s[i - 1];
			}
		}
		cout << endl;
	}
}
