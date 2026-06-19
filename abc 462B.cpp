// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v[n + 1];
	int k, t;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		while (k--) {
			cin >> t;
			v[t].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i].size();
		for (auto a : v[i]) {
			cout << " " << a;
		}
		cout << endl;
	}
}
