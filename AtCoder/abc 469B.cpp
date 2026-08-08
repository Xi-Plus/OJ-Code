// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') continue;
		if (i > 0 && s[i - 1] == 'o') continue;
		if (i < n - 1 && s[i + 1] == 'o') continue;
		ans++;
	}
	cout << ans << endl;
}
