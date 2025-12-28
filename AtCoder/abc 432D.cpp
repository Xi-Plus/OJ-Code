// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Zone {
	long long x1, x2, y1, y2;
};

bool overlay(Zone& a, Zone& b) {
	// cout << a.x1 << " " << a.x2 << " " << a.y1 << " " << a.y2 << " " << b.x1 << " " << b.x2 << " " << b.y1 << " " << b.y2 << endl;
	if (max(a.y2, b.y2) - min(a.y1, b.y1) <= a.y2 - a.y1 + b.y2 - b.y1 && max(a.x2, b.x2) - min(a.x1, b.x1) <= a.x2 - a.x1 + b.x2 - b.x1) {
		if (max(a.y2, b.y2) - min(a.y1, b.y1) == a.y2 - a.y1 + b.y2 - b.y1 && max(a.x2, b.x2) - min(a.x1, b.x1) == a.x2 - a.x1 + b.x2 - b.x1) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

int parent[1 << 14 + 5];
long long area[1 << 14 + 5];
int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	vector<Zone> cur, next;
	cur.push_back({0, x, 0, y});
	char c;
	long long a, b;
	while (n--) {
		cin >> c >> a >> b;
		next.clear();
		if (c == 'X') {
			for (auto& z : cur) {
				if (z.x1 >= a) {
					next.push_back({z.x1, z.x2, z.y1 + b, z.y2 + b});
				} else if (z.x2 <= a) {
					next.push_back({z.x1, z.x2, z.y1 - b, z.y2 - b});
				} else {
					next.push_back({z.x1, a, z.y1 - b, z.y2 - b});
					next.push_back({a, z.x2, z.y1 + b, z.y2 + b});
				}
			}
		} else {
			for (auto& z : cur) {
				if (z.y1 >= a) {
					next.push_back({z.x1 + b, z.x2 + b, z.y1, z.y2});
				} else if (z.y2 <= a) {
					next.push_back({z.x1 - b, z.x2 - b, z.y1, z.y2});
				} else {
					next.push_back({z.x1 - b, z.x2 - b, z.y1, a});
					next.push_back({z.x1 + b, z.x2 + b, a, z.y2});
				}
			}
		}
		swap(cur, next);
	}
	for (int i = 0; i < cur.size(); i++) {
		// cout << "zone i=" << i << " " << cur[i].x1 << " " << cur[i].x2 << " " << cur[i].y1 << " " << cur[i].y2 << endl;
		parent[i] = i;
		area[i] = (cur[i].x2 - cur[i].x1) * (cur[i].y2 - cur[i].y1);
	}
	int px, py;
	for (int i = 0; i < cur.size(); i++) {
		for (int j = i + 1; j < cur.size(); j++) {
			if (overlay(cur[i], cur[j])) {
				px = findParent(i);
				py = findParent(j);
				if (px != py) {
					parent[py] = px;
					// cout << "set parent " << py << " -> " << px << endl;
					area[px] += area[py];
					// cout << "area " << px << " " << area[px] << endl;
				}
			}
		}
	}
	vector<long long> ans;
	for (int i = 0; i < cur.size(); i++) {
		// cout << "parent " << i << " " << findParent(i) << endl;
		if (findParent(i) == i) {
			// cout << "area " << i << " " << area[i] << endl;
			ans.push_back(area[i]);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}
