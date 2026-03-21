// By xiplus
// WA
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
	T,
	null_type,
	less<T>,
	rb_tree_tag,
	tree_order_statistics_node_update>;

int cnt[500005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& v : a) {
		cin >> v;
		cnt[v]++;
	}
	vector<pair<int, int>> cnt2;
	for (int i = 1; i <= m; i++) {
		cnt2.push_back({cnt[i], i});
	}
	sort(cnt2.begin(), cnt2.end());
	// cout << "cnt:" << endl;
	// for (auto [cnt, i] : cnt2) {
	// 	cout << cnt << " " << i << endl;
	// }
	// cout << endl;
	cnt2.push_back({2e9, -1});

	int q;
	cin >> q;
	vector<long long> x(q);
	for (auto& v : x) {
		cin >> v;
		v--;
	}
	vector<int> xid(q);
	iota(xid.begin(), xid.end(), 0);
	sort(xid.begin(), xid.end(), [&](int i, int j) {
		return x[i] < x[j];
	});
	vector<int> ans(q);
	long long prev = n, nextIdx;
	ordered_set<int> s;
	int curI = 0, prevCnt = 0;
	int curXi = 0;
	while (x[xid[curXi]] < n) {
		// cout << "set " << xid[curXi] << " " << x[xid[curXi]] << " answer to " << a[x[xid[curXi]]] << endl;
		ans[xid[curXi]] = a[x[xid[curXi]]];
		curXi++;
	}
	// cout << "start x " << curXi << " " << xid[curXi] << " " << x[xid[curXi]] << endl;

	while (curI < m) {
		while (curI < m && cnt2[curI + 1].first == prevCnt) {
			s.insert(cnt2[curI].second);
			curI++;
		}
		if (curI == m - 1) {
			break;
		}
		// cout << "prev=" << prev << " curI=" << curI << " " << (cnt2[curI + 1].first - cnt2[curI].first) << " times: ";
		s.insert(cnt2[curI].second);
		// for (auto& v : s) {
		// 	cout << v << " ";
		// }
		// for (int j = 0; j <= i; j++) {
		// 	cout << cnt2[j].second << " ";
		// }
		// cout << endl;
		nextIdx = prev + (cnt2[curI + 1].first - cnt2[curI].first) * (curI + 1);
		// cout << "nextIdx=" << nextIdx << " " << curXi << " " << x[xid[curXi]] << endl;
		while (x[xid[curXi]] < nextIdx && curXi < q) {
			ans[xid[curXi]] = *s.find_by_order((x[xid[curXi]] - prev) % (curI + 1));
			// cout << "find " << x[xid[curXi]] << " " << ans[xid[curXi]] << endl;
			curXi++;
		}

		curI++;
		prevCnt = cnt2[curI].first;
		prev = nextIdx;
	}
	s.insert(cnt2[m - 1].second);
	// cout << "prev=" << prev << endl;
	// for (auto& v : s) {
	// 	cout << v << " ";
	// }
	// cout << endl;
	while (curXi < q) {
		ans[xid[curXi]] = *s.find_by_order((x[xid[curXi]] - prev) % m);
		// cout << "find " << x[xid[curXi]] << " " << ans[xid[curXi]] << endl;
		curXi++;
	}
	// cout << "ans: " << endl;
	for (auto v : ans) {
		cout << v << endl;
	}
}
