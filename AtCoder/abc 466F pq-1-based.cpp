// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
	int n;
	long long x;
	cin >> n >> x;
	priority_queue<pair<long long, long long>> pq;
	pq.push({x, 1});
	long long v;
	long long ans = 0;
	while (n--) {
		cin >> v;
		while (!pq.empty() && pq.top().first >= v) {
			auto [len, cnt] = pq.top();
			pq.pop();
			while (!pq.empty() && pq.top().first == len) {
				cnt += pq.top().second;
				pq.pop();
			}
			ans += len / v * cnt;
			pq.push({v - 1, len / v * cnt});
			if (len % v) {
				pq.push({len % v, cnt});
			}
		}
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
