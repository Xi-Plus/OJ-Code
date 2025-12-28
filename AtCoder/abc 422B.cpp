// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	char a[25][25];
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> a[i][j];
		}
	}
	bool ans = true;
	int cnt;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (a[i][j] != '#') {
				continue;
			}
			cnt = (a[i][j + 1] == '#') + (a[i][j - 1] == '#') + (a[i + 1][j] == '#') + (a[i - 1][j] == '#');
			if (cnt != 2 && cnt != 4) {
				ans = false;
			}
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
