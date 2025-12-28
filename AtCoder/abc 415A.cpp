// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int v[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int x;
	cin >> x;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		if (v[i] == x) {
			ans = true;
			break;
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
