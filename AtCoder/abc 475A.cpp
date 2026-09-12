// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	cout << s[0];
	for (int i = 1; i < s.size(); i++) {
		cout << "o" << s[i];
	}
	cout << endl;
}
