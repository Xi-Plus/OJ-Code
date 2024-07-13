// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	while (cin >> n && n) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; i++) {
			cin >> a;
			pq.push(a);
		}
		int ans = 0;
		while (pq.size() > 1) {
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << endl;
	}
}
