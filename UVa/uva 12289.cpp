// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s.size() == 5) {
			cout << 3 << endl;
		} else if ((s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e') >= 2) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
}
