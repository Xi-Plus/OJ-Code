// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct State {
	long long loss;
	int lastIdx;
	int count;
	bool operator<(const State& rhs) const {
		return loss > rhs.loss;
	}
};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k, x;
	cin >> n >> k >> x;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<long long>());
	long long d[n - 1];
	for (int i = 0; i < n - 1; i++) {
		d[i] = a[0] - a[i + 1];
	}
	long long maxSum = a[0] * k;
	cout << maxSum << endl;
	priority_queue<State> pq;
	pq.push({d[0], 0, 1});
	x--;
	while (x--) {
		auto cur = pq.top();
		pq.pop();
		cout << maxSum - cur.loss << endl;
		if (cur.lastIdx + 1 < n - 1) {
			pq.push({cur.loss - d[cur.lastIdx] + d[cur.lastIdx + 1],
					 cur.lastIdx + 1,
					 cur.count});
		}
		if (cur.count < k) {
			pq.push({cur.loss + d[cur.lastIdx],
					 cur.lastIdx,
					 cur.count + 1});
		}
	}
}
