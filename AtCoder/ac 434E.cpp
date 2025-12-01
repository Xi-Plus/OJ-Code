// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> parent, cntE, cntV;
int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int x, r;
	vector<int> a(n), b(n);
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> x >> r;
		a[i] = x + r;
		b[i] = x - r;
		s.insert(a[i]);
		s.insert(b[i]);
	}
	vector<int> s2(s.begin(), s.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(s2.begin(), s2.end(), a[i]) - s2.begin();
		b[i] = lower_bound(s2.begin(), s2.end(), b[i]) - s2.begin();
	}
	parent.resize(s2.size());
	cntE.resize(s2.size());
	cntV.resize(s2.size());
	for (int i = 0; i < s2.size(); i++) {
		parent[i] = i;
		cntE[i] = 0;
		cntV[i] = 1;
	}
	int pa, pb;
	for (int i = 0; i < n; i++) {
		pa = findParent(a[i]);
		pb = findParent(b[i]);
		cntE[pa]++;
		if (pa != pb) {
			parent[pb] = pa;
			cntE[pa] += cntE[pb];
			cntV[pa] += cntV[pb];
		}
	}
	int ans = 0;
	for (int i = 0; i < s2.size(); i++) {
		if (parent[i] == i) {
			ans += min(cntE[i], cntV[i]);
		}
	}
	cout << ans << endl;
}
