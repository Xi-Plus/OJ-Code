// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long ksum = 0, maxh = 0, ans = 0, h, k;
	while (n--) {
		cin >> k;
		long long rowh = 0;
		for (int i = 0; i < k; i++) {
			cin >> h;
			rowh = max(rowh, h);
		}
		if (rowh > maxh) {
			ans += ksum * (rowh - maxh);
			maxh = rowh;
		} else {
			ans += (maxh - rowh) * k;
		}
		ksum += k;
	}
	cout << ans << endl;
	return 0;
}
/*
2
4 3 2 1 1
6 4 2 5 4 3 2

6
7 4 6 1 2 4 2 5
6 11 8 4 2 3 6
4 3 2 5 2
5 4 4 4 4 4
3 12 15 10
1 7
*/
