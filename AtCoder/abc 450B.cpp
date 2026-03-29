// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int v[105][105];
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}
	bool found = false;
	for (int a = 1; a <= n; a++) {
		for (int b = a + 1; b <= n; b++) {
			for (int c = b + 1; c <= n; c++) {
				if (v[a][b] + v[b][c] < v[a][c]) {
					found = true;
					break;
				}
			}
		}
	}
	if (found) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
