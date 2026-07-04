// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w;
	cin >> h >> w;
	char v[h][w];
	int t = 1e9, b = 0, l = 1e9, r = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> v[i][j];
			if (v[i][j] == '#') {
				t = min(i, t);
				b = max(b, i);
				l = min(l, j);
				r = max(r, j);
			}
		}
	}
	for (int i = t; i <= b; i++) {
		for (int j = l; j <= r; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
}
