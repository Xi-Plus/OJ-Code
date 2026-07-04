// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<char>> m;
const char EMPTY = '?';
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, q;
	cin >> h >> w >> q;
	m.assign(h + 2, vector<char>(w + 2, EMPTY));
	vector<int> R(q + 1), C(q + 1);
	vector<char> X(q + 1);
	R[0] = h;
	C[0] = w;
	X[0] = 'A';
	for (int i = 1; i <= q; i++) {
		cin >> R[i] >> C[i] >> X[i];
	}
	for (int i = q; i >= 0; i--) {
		for (int r = R[i]; r >= 1; r--) {
			if (m[r][C[i]] != EMPTY) {
				break;
			}
			for (int c = C[i]; c >= 1; c--) {
				if (m[r][c] != EMPTY) {
					break;
				}
				m[r][c] = X[i];
			}
		}
	}
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= w; c++) {
			cout << m[r][c];
		}
		cout << endl;
	}
}
