// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Pc {
	int ver, cnt;
	bool operator<(const Pc& other) const {
		return ver > other.ver;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	priority_queue<Pc> pq;
	for (int i = 1; i <= n; i++) {
		pq.push({i, 1});
	}
	int x, y, cnt;
	while (q--) {
		cin >> x >> y;
		cnt = 0;
		while (pq.top().ver <= x) {
			cnt += pq.top().cnt;
			pq.pop();
		}
		cout << cnt << endl;
		pq.push({y, cnt});
	}
}
