// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string s, t;
	cin >> s >> t;
	int idx1 = 0, idx2 = 0;
	int cnt1 = 0, cnt2 = 0;
	int ans = 0;
	bool error = false;
	while (idx1 < s.size() && idx2 < t.size()) {
		while (s[idx1] == 'A') {
			idx1++;
			cnt1++;
		}
		while (t[idx2] == 'A') {
			idx2++;
			cnt2++;
		}
		// cout << "idx " << idx1 << " " << idx2 << " " << cnt1 << " " << cnt2 << endl;
		if (s[idx1] != t[idx2]) {
			error = true;
			break;
		}
		ans += abs(cnt1 - cnt2);
		cnt1 = 0;
		cnt2 = 0;
		idx1++;
		idx2++;
	}
	while (idx1 < s.size() && s[idx1] == 'A') {
		idx1++;
		cnt1++;
	}
	while (idx2 < t.size() && t[idx2] == 'A') {
		idx2++;
		cnt2++;
	}
	if (idx1 < s.size() || idx2 < t.size()) {
		error = true;
	} else {
		ans += abs(cnt1 - cnt2);
	}
	if (error) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}
