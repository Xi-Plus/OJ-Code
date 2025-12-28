// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	int ans = 2e9;
	for (int i = 0; i <= n - m; i++) {
		int temp = 0;
		for (int j = 0; j < m; j++) {
			if (s[i + j] < t[j]) {
				temp += 10 - (t[j] - s[i + j]);
			} else {
				temp += s[i + j] - t[j];
			}
		}
		ans = min(ans, temp);
	}
	cout << ans << endl;
}
