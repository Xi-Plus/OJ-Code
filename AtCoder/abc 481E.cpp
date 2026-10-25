// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Point {
	long long x, y;
	int side() const {
		if (x > 0) {
			return -1;
		} else if (x == 0) {
			if (y < 0) {
				return -1;
			} else {
				return 1;
			}
		} else {
			return 1;
		}
	}
	int zone() const {
		if (x == 0) {
			return 1;
		} else {
			return 2;
		}
	}
	bool operator<(const Point& other) const {
		if (this->zone() == other.zone()) {
			// return (long double)y / x < (long double)other.y / other.x;
			if (x > 0 && other.x > 0) {
				return y * other.x < other.y * x;
			} else if (x < 0 && other.x < 0) {
				return y * other.x < other.y * x;
			} else {
				return y * other.x > other.y * x;
			}
		} else {
			return this->zone() < other.zone();
		}
	}
};

void sol() {
	int n;
	cin >> n;
	vector<Point> p(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		if (p[i].side() == -1) {
			cnt++;
		}
	}
	sort(p.begin(), p.end());
	int ans = max(cnt, n - cnt);
	for (int i = 0; i < n; i++) {
		cnt += p[i].side();
		ans = max(ans, cnt);
		ans = max(ans, n - cnt);
	}
	cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
