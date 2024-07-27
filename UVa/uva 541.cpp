// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n) {
		int v[n][n];
		for (int q = 0; q < n; q++) {
			for (int w = 0; w < n; w++) {
				cin >> v[q][w];
			}
		}
		int cntx = 0, cnty = 0, x, y;
		for (int q = 0; q < n; q++) {
			int sum = 0;
			for (int w = 0; w < n; w++) {
				sum += v[q][w];
			}
			if (sum % 2 == 1) {
				cntx++;
				x = q + 1;
			}
		}
		for (int w = 0; w < n; w++) {
			int sum = 0;
			for (int q = 0; q < n; q++) {
				sum += v[q][w];
			}
			if (sum % 2 == 1) {
				cnty++;
				y = w + 1;
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
