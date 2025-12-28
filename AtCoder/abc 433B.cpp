// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		bool found = false;
		for (int j = i - 1; j >= 1; j--) {
			if (a[j] > a[i]) {
				cout << j << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << -1 << endl;
		}
	}
}
