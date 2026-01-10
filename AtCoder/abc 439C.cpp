// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[3500];
	for (int i = 0; i < 3500; i++) {
		a[i] = i * i;
	}
	map<int, int> cnt;
	long long t;
	for (int i = 1;; i++) {
		for (int j = i + 1;; j++) {
			t = a[i] + a[j];
			if (t <= n) {
				cnt[t]++;
			} else {
				break;
			}
		}
		if (a[i] * 2 > n) {
			break;
		}
	}
	vector<int> ans;
	for (auto [v, c] : cnt) {
		if (c == 1) {
			ans.push_back(v);
		}
	}
	cout << ans.size() << endl;
	for (auto v : ans) {
		cout << v << " ";
	}
	cout << endl;
}
