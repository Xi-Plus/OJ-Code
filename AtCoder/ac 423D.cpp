// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Data {
	long long enter, use, cnt;
};
struct Node {
	long long t, cnt;
	bool operator<(const Node& rhs) const {
		return t > rhs.t;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	Data data[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i].enter >> data[i].use >> data[i].cnt;
	}
	long long curT = 0;
	priority_queue<Node> pq;
	for (int waitIdx = 0; waitIdx < n; waitIdx++) {
		curT = max(curT, data[waitIdx].enter);
		while (k < data[waitIdx].cnt) {
			k += pq.top().cnt;
			curT = max(curT, pq.top().t);
			pq.pop();
		}
		cout << curT << endl;
		pq.push({curT + data[waitIdx].use, data[waitIdx].cnt});
		k -= data[waitIdx].cnt;
	}
}
