// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool dp[k + 1] = {};
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - a[j] >= 0 && !dp[i - a[j]]) {
				dp[i] = true;
				break;
			}
		}
	}
	if (dp[k]) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
}
