// By xiplus
#include <bits/stdc++.h>
// #define endl '\n'
using namespace std;

string s;
bool check(int l, int r) {
	cout << "? " << l << " " << r << endl;
	cin >> s;
	return s[0] == 'Y';
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int l = 1;
	for (int r = 2; r <= n; r++) {
		while (l < r && !check(l, r)) {
			l++;
		}
		ans += r - l;
	}
	cout << "! " << ans << endl;
}
