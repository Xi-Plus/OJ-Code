// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int dessert = 2;
const int drink = 1;
struct Food {
	int type;
	long long price;
	bool operator<(Food& other) {
		if (price == other.price) {
			return type < other.type;
		}
		return price < other.price;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long n, m, k, x, y;
	cin >> n >> m >> k;
	cin >> x >> y;
	vector<Food> v(n + m);
	for (int i = 0; i < n; i++) {
		cin >> v[i].price;
		v[i].type = dessert;
	}
	for (int i = 0; i < m; i++) {
		cin >> v[i + n].price;
		v[i + n].type = drink;
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	long long curX = 0, curY = 0, reqX, reqY;
	long long total = x + y * k;
	for (int i = 0; i < n + m; i++) {
		if (v[i].type == dessert) {
			reqX = curX + v[i].price;
			reqY = curY;
			if (reqY <= y && reqX + reqY * k <= total) {
				ans++;
				curX = reqX;
				curY = reqY;
			}
		} else {
			long long used = (v[i].price - 1) / k + 1;
			reqY = curY + used;
			reqX = curX - (used * k - v[i].price);
			if (reqY <= y && reqX + reqY * k <= total) {
				ans++;
				curX = reqX;
				curY = reqY;
			}
		}
	}
	cout << ans << endl;
}
