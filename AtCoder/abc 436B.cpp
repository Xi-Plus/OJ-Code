// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[n][n] = {};
	int cnt = n * n - 1;
	int r = 0, c = (n - 1) / 2;
	a[r][c] = 1;
	int k = 2;
	while (cnt--) {
		if (a[(r - 1 + n) % n][(c + 1) % n] == 0) {
			r = (r - 1 + n) % n;
			c = (c + 1) % n;
		} else {
			r = (r + 1) % n;
		}
		a[r][c] = k;
		k++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
