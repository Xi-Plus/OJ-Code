// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int i = 0;
	bool mode = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '#') {
			cout << i + 1;
			if (mode) {
				cout << ",";
			} else {
				cout << endl;
			}
			mode = !mode;
		}
	}
}
