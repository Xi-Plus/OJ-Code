// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans(n);
	vector<int> xpos;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			xpos.push_back(i + 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i > xpos.size()) {
			cout << n << endl;
		} else {
			cout << xpos[i - 1] << endl;
		}
	}
}
