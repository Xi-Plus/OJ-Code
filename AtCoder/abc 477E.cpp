// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long

int a[200005];
int b[200005];
int dis1[200005];
int dis2[200005];
struct Node {
	int dis, idx;
	bool operator<(const Node& other) const {
		return dis > other.dis;
	}
};

priority_queue<Node> pq;

signed main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int total = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dis1[i + 1] = dis1[i] + a[i];
		total += a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		pq.push({b[i], i});
	}
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dis2[cur.idx]) {
			continue;
		}
		dis2[cur.idx] = cur.dis;
		int prev = cur.idx - 1;
		if (prev == 0) {
			prev = n;
		}
		if (dis2[prev] == 0) {
			pq.push({cur.dis + a[prev], prev});
		}
		int next = cur.idx + 1;
		if (next > n) {
			next = 1;
		}
		if (dis2[next] == 0) {
			pq.push({cur.dis + a[cur.idx], next});
		}
	}
	dis2[n + 1] = 0;
	// for (int i = 1; i <= n; i++) {
	// 	cerr << dis2[i] << " ";
	// }
	// cerr << endl;
	int s, t;
	while (q--) {
		cin >> s >> t;
		if (t == n + 1) {
			cout << dis2[s] << endl;
		} else {
			int a = dis1[t] - dis1[s];
			int b = total - a;
			int c = dis2[s] + dis2[t];
			cout << min(min(a, b), c) << endl;
		}
	}
}
