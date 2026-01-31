// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	char c;
	cin >> n;
	int a[n + 1][n + 1] = {}, b[n + 1][n + 1] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == '#') {
				a[i][j] = a[i][j - 1] + 1;
			} else {
				a[i][j] = a[i][j - 1];
			}
		}
		b[i][0] = a[i][n];
		for (int j = 1; j <= n; j++) {
			b[i][j] = a[i][n - j] + j - (a[i][n] - a[i][n - j]);
		}
	}
	// cout << "a:" << endl;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "b:" << endl;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << b[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int d[n + 1][n + 1] = {};
	for (int j = 0; j <= n; j++) {
		d[1][j] = b[1][j];
	}
	for (int i = 2; i <= n; i++) {
		int rowMin = d[i - 1][0];
		for (int j = 0; j <= n; j++) {
			rowMin = min(rowMin, d[i - 1][j]);
			d[i][j] = b[i][j] + rowMin;
		}
	}
	// cout << "d:" << endl;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << d[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = d[n][0];
	for (int j = 1; j <= n; j++) {
		ans = min(ans, d[n][j]);
	}
	cout << ans << endl;
}
