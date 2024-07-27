// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, t;
	while (cin >> n && n) {
		int r[n] = {}, c[n] = {};
		for (int q = 0; q < n; q++) {
			for (int w = 0; w < n; w++) {
				cin >> t;
				r[q] += t;
				c[w] += t;
			}
		}
		int cntx = 0, cnty = 0, x, y;
		for (int q = 0; q < n; q++) {
			if (r[q] % 2 == 1) {
				cntx++;
				x = q + 1;
			}
			if (c[q] % 2 == 1) {
				cnty++;
				y = q + 1;
			}
		}

		if (cntx == 0 && cnty == 0) {
			cout << "OK" << endl;
		} else if (cntx == 1 && cnty == 1) {
			cout << "Change bit (" << x << "," << y << ")" << endl;
		} else {
			cout << "Corrupt" << endl;
		}
	}
}
/*
4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 1 1 0
1 1 1 1
0 1 0 1
0
*/
