// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int ida = 0, idb = 0, idc = 0, ans = 0;
	while (true) {
		while (s[ida] != 'A' && ida < s.size()) {
			ida++;
		}
		idb = max(idb, ida + 1);
		while (s[idb] != 'B' && idb < s.size()) {
			idb++;
		}
		idc = max(idc, idb + 1);
		while (s[idc] != 'C' && idc < s.size()) {
			idc++;
		}
		if (ida < s.size() && idb < s.size() && idc < s.size()) {
			ans++;
			ida++;
			idb++;
			idc++;
		} else {
			break;
		}
	}
	cout << ans << endl;
}
