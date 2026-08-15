// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	vector<long long> vl, vr;
	long long t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t > 0) {
			vr.push_back(t);
		} else {
			vl.push_back(t);
		}
	}
	sort(vl.begin(), vl.end());
	sort(vr.begin(), vr.end(), greater<>());
	long long ans = 0, cur = 0;
	while (vl.size() > 0 && vr.size() > 0) {
		if (abs(vl.back() - cur) <= abs(vr.back() - cur)) {
			ans += abs(vl.back() - cur);
			cur = vl.back();
			vl.pop_back();
		} else {
			ans += abs(vr.back() - cur);
			cur = vr.back();
			vr.pop_back();
		}
	}
	while (vl.size()) {
		ans += abs(vl.back() - cur);
		cur = vl.back();
		vl.pop_back();
	}
	while (vr.size()) {
		ans += abs(vr.back() - cur);
		cur = vr.back();
		vr.pop_back();
	}
	cout << ans << endl;
}
