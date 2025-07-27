// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long dis[501][501];
const long long MAX_DIS = 1e18;
int n, m;
long long getDis(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	return dis[a][b];
}
void setDis(int a, int b, int c) {
	if (a > b) {
		swap(a, b);
	}
	dis[a][b] = c;
}
void update() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (getDis(i, j) > getDis(i, k) + getDis(k, j)) {
					setDis(i, j, getDis(i, k) + getDis(k, j));
				}
			}
		}
	}
}
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] == MAX_DIS) {
				cout << -1 << " ";
			} else {
				cout << dis[i][j] << " ";
			}
		}
		cout << endl;
	}
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dis[i][j] = MAX_DIS;
		}
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dis[a][b] = c;
	}
	int k, t;
	cin >> k >> t;
	vector<int> d(k);
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (getDis(d[i], d[j]) > t) {
				setDis(d[i], d[j], t);
			}
		}
	}
	int q;
	cin >> q;
	int type;
	int x, y, tt;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> tt;
			if (getDis(x, y) > tt) {
				setDis(x, y, tt);
			}
		} else if (type == 2) {
			cin >> x;
			for (int i = 0; i < d.size(); i++) {
				if (getDis(x, d[i]) > t) {
					setDis(x, d[i], t);
				}
			}
		} else {
			update();
			long long ans = 0;
			for (int i = 1; i <= n - 1; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (getDis(i, j) != MAX_DIS) {
						ans += getDis(i, j);
					}
				}
			}
			cout << ans * 2 << endl;
		}
		// cout << "------" << endl;
		// print();
	}
}
