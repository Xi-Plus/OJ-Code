// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Data {
	int enter, use, cnt;
};
struct Node {
	int t, cnt;
	bool operator<(const Node& rhs) const {
		return t > rhs.t;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	Data data[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> data[i].enter >> data[i].use >> data[i].cnt;
	}
	data[n].cnt = k + 1;
	int curT = 0, waitIdx = 0;
	priority_queue<Node> pq;
	while (true) {
		while (data[waitIdx].cnt <= k) {
			curT = max(curT, data[waitIdx].enter);
			cout << curT << endl;
			k -= data[waitIdx].cnt;
			pq.push({curT + data[waitIdx].use, data[waitIdx].cnt});
			waitIdx++;
		}
		if (waitIdx == n) {
			break;
		}
		while (pq.top().t <= curT) {
			k += pq.top().cnt;
			pq.pop();
		}
		while (k < data[waitIdx].cnt) {
			curT = pq.top().t;
			k += pq.top().cnt;
			pq.pop();
		}
	}
}
