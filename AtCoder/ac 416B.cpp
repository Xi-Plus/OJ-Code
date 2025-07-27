// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int i = 0;
	bool found = true;
	while (i < s.size()) {
		if (s[i] == '#') {
			found = true;
		} else {
			if (found) {
				s[i] = 'o';
				found = false;
			}
		}
		i++;
	}
	cout << s << endl;
}
