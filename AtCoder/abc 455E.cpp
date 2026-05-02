// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[200005], b[200005], c[200005], d[200005], e[200005], f[200005];
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i] + (s[i] == 'A');
		b[i + 1] = b[i] + (s[i] == 'B');
		c[i + 1] = c[i] + (s[i] == 'C');
	}
	long long ans = (long long)n * (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - b[i];
		e[i] = b[i] - c[i];
		f[i] = a[i] - c[i];
	}
	unordered_map<int, int> cnt1;
	for (int i = 0; i <= n; i++) {
		cnt1[d[i]]++;
	}
	for (auto [v, c] : cnt1) {
		ans -= (long long)c * (c - 1) / 2;
	}

	unordered_map<int, int> cnt2;
	for (int i = 0; i <= n; i++) {
		cnt2[e[i]]++;
	}
	for (auto [v, c] : cnt2) {
		ans -= (long long)c * (c - 1) / 2;
	}

	unordered_map<int, int> cnt3;
	for (int i = 0; i <= n; i++) {
		cnt3[f[i]]++;
	}
	for (auto [v, c] : cnt3) {
		ans -= (long long)c * (c - 1) / 2;
	}

	map<pair<int, int>, int> cnt4;
	for (int i = 0; i <= n; i++) {
		cnt4[{d[i], e[i]}]++;
	}
	for (auto [v, c] : cnt4) {
		ans += (long long)c * (c - 1) / 2;
	}

	map<pair<int, int>, int> cnt5;
	for (int i = 0; i <= n; i++) {
		cnt5[{d[i], f[i]}]++;
	}
	for (auto [v, c] : cnt5) {
		ans += (long long)c * (c - 1) / 2;
	}

	map<pair<int, int>, int> cnt6;
	for (int i = 0; i <= n; i++) {
		cnt6[{e[i], f[i]}]++;
	}
	for (auto [v, c] : cnt6) {
		ans += (long long)c * (c - 1) / 2;
	}

	map<tuple<int, int, int>, int> cnt7;
	for (int i = 0; i <= n; i++) {
		cnt7[{d[i], e[i], f[i]}]++;
	}
	for (auto [v, c] : cnt7) {
		ans -= (long long)c * (c - 1) / 2;
	}

	cout << ans << endl;
}
