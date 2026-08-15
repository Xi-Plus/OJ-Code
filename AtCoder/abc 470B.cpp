// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> c(n + 1, 0);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		c[t]++;
	}
	int maxc = 0;
	for (int i = 1; i <= n; i++) {
		maxc = max(maxc, c[i]);
	}
	cout << n - maxc << endl;
}
