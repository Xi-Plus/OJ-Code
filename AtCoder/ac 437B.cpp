// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int h, w, n;
	cin >> h >> w >> n;
	unordered_map<int, int> map;
	int x;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> x;
			map[x] = i;
		}
	}
	int cnt[h] = {};
	while (n--) {
		cin >> x;
		if (map.find(x) != map.end()) {
			cnt[map[x]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		ans = max(ans, cnt[i]);
	}
	cout << ans << endl;
}
