// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	bool ans = true;
	for (int i = 1; i <= n; i++) {
		if (b[a[i]] != i) {
			ans = false;
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}
