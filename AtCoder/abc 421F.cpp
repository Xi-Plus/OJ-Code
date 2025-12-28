// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q, t, x, y;
	cin >> q;
	vector<int> a(q + 1);
	a[0] = -1;
	for (int i = 1; i <= q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			a[i] = a[x];
			a[x] = i;
		} else {
			cin >> x >> y;
			int curX = x, curY = y;
			long long ansX = 0, ansY = 0;
			while (true) {
				if (a[curX] != -1) {
					curX = a[curX];
					if (curX == y) {
						cout << ansX << endl;
						a[x] = y;
						break;
					}
					ansX += curX;
				}
				if (a[curY] != -1) {
					curY = a[curY];
					if (curY == x) {
						cout << ansY << endl;
						a[y] = x;
						break;
					}
					ansY += curY;
				}
			}
		}
	}
}
