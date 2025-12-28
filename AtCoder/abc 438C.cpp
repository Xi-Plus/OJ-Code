// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int s[n];
	int len = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[len];
		len++;
		if (s[len - 1] == s[len - 2] && s[len - 2] == s[len - 3] && s[len - 3] == s[len - 4]) {
			len -= 4;
		}
	}
	cout << len << endl;
}
