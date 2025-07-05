// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, m, total = 0, t;
	cin >> n >> m;
	while (n--) {
		cin >> t;
		total += t;
	}
	if (total <= m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
