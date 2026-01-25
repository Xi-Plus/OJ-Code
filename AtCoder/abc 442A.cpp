// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	for (auto c : s) {
		if (c == 'i' || c == 'j') {
			ans += 1;
		}
	}
	cout << ans << endl;
}
