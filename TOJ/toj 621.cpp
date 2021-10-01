#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, m, x, y;
	char c;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		x = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c;
				if (c == '*') {
					x = i;
					y = j;
				}
			}
		}
		if (x != -1) {
			cout << x << " " << y << endl;
		} else {
			cout << "I CAN'T FIND IT QQ" << endl;
		}
	}
}
