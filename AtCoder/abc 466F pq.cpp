// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
	int n;
	long long x;
	cin >> n >> x;
	priority_queue<pair<long long, long long>> pq;
	pq.push({x + 1, 1});
	long long v;
	while (n--) {
		cin >> v;
		while (!pq.empty() && pq.top().first > v) {
			auto [len, cnt] = pq.top();
			pq.pop();
			while (!pq.empty() && pq.top().first == len) {
				cnt += pq.top().second;
				pq.pop();
			}
			pq.push({v, len / v * cnt});
			if (len % v) {
				pq.push({len % v, cnt});
			}
		}
	}
	long long ans = -1;
	while (!pq.empty()) {
		ans += pq.top().second;
		pq.pop();
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
