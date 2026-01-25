// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int zone(int x, int y) {
	if (x > 0 && y <= 0) {
		return 1;
	} else if (x <= 0 && y < 0) {
		return 2;
	} else if (x < 0 && y >= 0) {
		return 3;
	} else {
		return 4;
	}
}
struct Point {
	long long x, y;
	vector<int> idx;
	bool operator<(const Point& rhs) const {
		int z1 = zone(x, y), z2 = zone(rhs.x, rhs.y);
		if (z1 != z2) {
			return z1 < z2;
		} else {
			if (z1 == 1) {
				// -y/x < -rhs.y/rhs.x
				return -y * rhs.x < -rhs.y * x;
			} else if (z1 == 2) {
				// -x/-y < -rhs.x/-rhs.y
				return x * rhs.y < rhs.x * y;
			} else if (z1 == 3) {
				// y/-x < rhs.y/-rhs.x
				return y * (-rhs.x) < rhs.y * (-x);
			} else {
				// x/y < rhs.x/rhs.y
				return x * rhs.y < rhs.x * y;
			}
		}
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<Point> p;
	map<pair<int, int>, int> m;
	int x, y, gcd;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x == 0) {
			y = (y > 0) ? 1 : -1;
		} else if (y == 0) {
			x = (x > 0) ? 1 : -1;
		} else {
			gcd = abs(__gcd(x, y));
			x /= gcd;
			y /= gcd;
		}
		if (m.count({x, y})) {
			p[m[{x, y}]].idx.push_back(i + 1);
		} else {
			p.push_back({x, y, {i + 1}});
			m[{x, y}] = p.size() - 1;
		}
	}
	sort(p.begin(), p.end());
	int find[n + 1] = {};
	vector<int> sum;
	sum.push_back(0);
	for (int i = 0; i < p.size(); i++) {
		// cout << i + 1 << " (" << p[i].x << "," << p[i].y << ") " << zone(p[i].x, p[i].y) << " ";
		for (auto& idx : p[i].idx) {
			find[idx] = i + 1;
			// cout << idx << " ";
		}
		// cout << endl;
		sum.push_back(sum.back() + p[i].idx.size());
	}

	int idx1, idx2;
	while (q--) {
		cin >> x >> y;
		idx1 = find[x];
		idx2 = find[y];
		// assert(idx1 != 0);
		// assert(idx2 != 0);
		// cout << x << " " << y << " " << idx1 << " " << idx2 << endl;
		if (idx1 <= idx2) {
			cout << sum[idx2] - sum[idx1 - 1] << endl;
		} else {
			cout << sum.back() - sum[idx1 - 1] + sum[idx2] << endl;
		}
	}
}
