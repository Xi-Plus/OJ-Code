// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int p, q, x, y;
	cin >> p >> q >> x >> y;
	if (p <= x && x < p + 100 && q <= y && y < q + 100) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
