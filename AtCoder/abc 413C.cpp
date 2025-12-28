// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	vector<pair<long long, long long>> seq;
	int idx = 0;
	int t, c, used;
	long long x;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> c >> x;
			seq.push_back({c, x});
		} else {
			cin >> x;
			long long ans = 0;
			while (x > 0) {
				used = min(x, seq[idx].first);
				ans += (long long)used * seq[idx].second;
				x -= used;
				seq[idx].first -= used;
				if (seq[idx].first == 0) {
					idx++;
				}
			}
			cout << ans << endl;
		}
	}
}
