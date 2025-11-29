// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve1() {
	// TLE
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (min(i + 1, n - (i + 1)) * 2 <= ans) {
			continue;
		}
		int l = i, r = i + 1;
		unordered_set<int> left, right, common;
		while (l >= 0 && r < n) {
			if (common.find(a[l]) == common.end()) {
				if (right.find(a[l]) != right.end()) {
					right.erase(a[l]);
					common.insert(a[l]);
				} else {
					left.insert(a[l]);
				}
			}
			if (common.find(a[r]) == common.end()) {
				if (left.find(a[r]) != left.end()) {
					left.erase(a[r]);
					common.insert(a[r]);
				} else {
					right.insert(a[r]);
				}
			}
			if (left.empty() && right.empty()) {
				ans = max(ans, r - l + 1);
			}
			l--;
			r++;
		}
	}
	cout << ans << endl;
}

void solve2() {
	// AC
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	vector<int> b(s.begin(), s.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	}
	vector<int> flagl(b.size(), -1);
	vector<int> flagr(b.size(), -1);
	int ans = 0;
	for (int center = 0; center < n - 1; center++) {
		int l = center, r = center + 1;
		int cntl = 0, cntr = 0, cntcom = 0;
		while (l >= 0 && r < n) {
			if (flagl[a[l]] != center) {
				flagl[a[l]] = center;
				cntl++;
				if (flagr[a[l]] == center) {
					cntcom++;
				}
			}
			if (flagr[a[r]] != center) {
				flagr[a[r]] = center;
				cntr++;
				if (flagl[a[r]] == center) {
					cntcom++;
				}
			}
			if (cntl == cntcom && cntr == cntcom) {
				ans = max(ans, r - l + 1);
			}
			l--;
			r++;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// solve1();
	solve2();
}
