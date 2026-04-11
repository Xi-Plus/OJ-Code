// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i = 0;
	while (i < s.size() && s[i] == 'o') {
		i++;
	}
	while (i < s.size()) {
		cout << s[i];
		i++;
	}
	cout << endl;
}
