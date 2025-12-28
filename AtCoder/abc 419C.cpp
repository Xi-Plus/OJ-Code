// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int minx, maxx, miny, maxy;
	cin >> minx >> miny;
	maxx = minx;
	maxy = miny;
	int x, y;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}
	cout << max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2) << endl;
	return 0;
}
