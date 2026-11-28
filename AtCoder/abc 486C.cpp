// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == 'o') {
			ans++;
		}
		for (int j = i + k; j < n; j += k) {
			if (s[j] == 'o' && s[j - k] != 'o') {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
