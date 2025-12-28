// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string a, b;
	cin >> n >> a >> b;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'o' && b[i] == 'o') {
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
