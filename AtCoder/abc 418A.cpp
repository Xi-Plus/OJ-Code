// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	if (n >= 3 && s[n - 3] == 't' && s[n - 2] == 'e' && s[n - 1] == 'a') {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
