// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int v[3][6];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> v[i][j];
		}
	}
	int cnt = 0;
	int a[3];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				a[0] = v[0][i];
				a[1] = v[1][j];
				a[2] = v[2][k];
				sort(a, a + 3);
				if (a[0] == 4 && a[1] == 5 && a[2] == 6) {
					cnt++;
				}
			}
		}
	}
	cout << fixed << setprecision(20) << 1.0 * cnt / 216 << endl;
}
