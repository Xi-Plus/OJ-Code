// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	long double len;
	int cnt;
	bool operator<(const Node& rhs) const {
		return len < rhs.len;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k, x;
		cin >> n >> k >> x;
		priority_queue<Node> pq;
		long double a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			pq.push({a, 1});
		}
		while (k) {
			auto [len, cnt] = pq.top();
			pq.pop();
			if (k >= cnt) {
				pq.push({len / 2, cnt * 2});
				k -= cnt;
			} else {
				pq.push({len / 2, k * 2});
				pq.push({len, cnt - k});
				k = 0;
			}
		}
		while (x) {
			auto [len, cnt] = pq.top();
			pq.pop();
			if (x <= cnt) {
				cout << fixed << setprecision(30) << len << endl;
				x = 0;
			} else {
				x -= cnt;
			}
		}
	}
}
