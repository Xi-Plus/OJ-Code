// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
// #define cerr if (true) {} else cerr
using namespace std;
#define int long long

const int MAXN = 200005;
int BIT[MAXN];
int lowbit(int x) {
	return x & -x;
}
void update(int x) {
	while (x < MAXN) {
		BIT[x]++;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while (x) {
		ans += BIT[x];
		x -= lowbit(x);
	}
	return ans;
}

signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> s(n), t(n);
	for (auto& v : s) {
		cin >> v;
	}
	for (auto& v : t) {
		cin >> v;
	}
	vector<int> oS(n), oT(n), rS(n), rT(n);
	iota(oS.begin(), oS.end(), 0);
	sort(oS.begin(), oS.end(), [&](int a, int b) {
		return s[a] < s[b];
	});
	iota(oT.begin(), oT.end(), 0);
	sort(oT.begin(), oT.end(), [&](int a, int b) {
		return t[a] < t[b];
	});
	for (int i = 0; i < n; i++) {
		rS[oS[i]] = i;
		rT[oT[i]] = i;
	}
	cerr << "oS ";
	for (auto& v : oS) {
		cerr << v << " ";
	}
	cerr << endl;
	cerr << "rS ";
	for (auto& v : rS) {
		cerr << v << " ";
	}
	cerr << endl;
	cerr << "oT ";
	for (auto& v : oT) {
		cerr << v << " ";
	}
	cerr << endl;
	cerr << "rT ";
	for (auto& v : rT) {
		cerr << v << " ";
	}
	cerr << endl;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int r = rT[oS[i]] + 1;
		ans += i - query(r);
		update(r);
	}
	for (int i = 0; i < n; i++) {
		ans += abs((t[i] - s[i]) - (rT[i] - rS[i]));
	}
	cout << ans << endl;
}
