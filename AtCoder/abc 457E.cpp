// By xiplus
// WA
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool pairlower(pair<int, int> a, int b) {
	return a.first < b;
}
bool pairupper(int b, pair<int, int> a) {
	return a.first > b;
}

vector<vector<pair<int, int>>> al, ar;
vector<int> all;
bool try1(int s, int t) {
	if (al[t].size() == 0 || ar[s].size() == 0) {
		// cerr << "nothing" << endl;
		return false;
	}
	// find right <= t
	auto itl = upper_bound(ar[s].begin(), ar[s].end(), t, pairupper);
	if (itl == ar[s].begin()) {
		// cerr << "not found right" << endl;
		return false;
	}
	itl--;
	int idr = itl - ar[s].begin();

	// find left >= s
	auto itr = lower_bound(al[t].begin(), al[t].end(), s, pairlower);
	if (itr == al[t].end()) {
		// cerr << "not found left" << endl;
		return false;
	}
	int idl = itr - al[t].begin();

	// cerr << "left ";
	for (auto v : al[t]) {
		// cerr << v.first << " ";
	}
	// cerr << "found " << idl << endl;
	// cerr << "right ";
	for (auto v : ar[s]) {
		// cerr << v.first << " ";
	}
	// cerr << "found " << idr << endl;

	if (al[t][idl].second == ar[s][idr].second) {
		if (idl + 1 < al[t].size() && al[t][idl + 1].first <= ar[s][idr].first + 1) {
			return true;
		}
		if (idr - 1 >= 0 && al[t][idl].first <= ar[s][idr - 1].first + 1) {
			return true;
		}
	} else {
		if (al[t][idl].first <= ar[s][idr].first + 1) {
			return true;
		}
	}

	if (ar[s][idr].first == t) {
		cerr << "found single cover" << endl;
		for (int i = 0; i < ar[s].size(); i++) {
			cerr << i << " " << ar[s][i].first << endl;
			if (i != idr && ar[s][i].first <= t) {
				return true;
			}
		}
		auto it = lower_bound(all.begin(), all.end(), s + 1);
		if (it != all.end()) {
			int val = *it;
			if (ar[val][0].first <= t) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	al.resize(n + 1);
	ar.resize(n + 1);
	int l, r;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		ar[l].push_back({r, i});
		al[r].push_back({l, i});
		all.push_back(l);
	}
	sort(all.begin(), all.end());
	for (int i = 1; i <= n; i++) {
		sort(al[i].begin(), al[i].end());
		sort(ar[i].begin(), ar[i].end());
	}
	int q;
	cin >> q;
	int s, t, idl, used;
	while (q--) {
		cin >> s >> t;
		// cerr << s << " " << t << endl;
		if (try1(s, t)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
