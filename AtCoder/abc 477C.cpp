// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	string s, t;
	cin >> s >> t;
	vector<int> ans;
	int sz1 = s.size() - t.size() + 1, sz2 = t.size();
	for (int i = 0; i < sz1; i++) {
		bool good = true;
		for (int j = 0; j < sz2; j++) {
			if (s[i + j] != t[j]) {
				good = false;
				break;
			}
		}
		if (good) {
			ans.push_back(i);
		}
	}
	int l, r;
	while (q--) {
		cin >> l >> r;
		l--;
		r--;
		auto it = lower_bound(ans.begin(), ans.end(), l);
		cerr << it - ans.begin() << endl;
		if (it != ans.end() && (*it) <= r - sz2 + 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
