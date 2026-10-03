// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Query {
	int pos, val;
	bool type;
	bool operator<(const Query& other) const {
		return pos < other.pos;
	}
};
int cnt[200005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int l, r, x;
	vector<Query> query;
	for (int i = 0; i < q; i++) {
		cin >> l >> r >> x;
		query.push_back({l, x, true});
		query.push_back({r + 1, x, false});
	}
	sort(query.begin(), query.end());
	int ans = 0, qi = 0;
	for (int i = 1; i <= n; i++) {
		cerr << i << endl;
		while (qi < query.size() && query[qi].pos <= i) {
			if (query[qi].type) {
				cnt[query[qi].val]++;
				if (cnt[query[qi].val] == 1) {
					ans++;
				}
			} else {
				cnt[query[qi].val]--;
				if (cnt[query[qi].val] == 0) {
					ans--;
				}
			}
			qi++;
		}
		cout << ans << " ";
	}
	cout << endl;
}
