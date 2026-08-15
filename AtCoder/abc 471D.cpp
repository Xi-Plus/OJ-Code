// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q, v;
	cin >> q >> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	int ty, tq, wq;
	while (q--) {
		cin >> ty;
		if (ty == 1) {
			cin >> tq >> wq;
			pq.push(tq + v - wq);
		} else {
			cin >> tq;
			if (pq.empty()) {
				cout << -1 << endl;
			} else {
				if (pq.top() > tq) {
					cout << v - (pq.top() - tq) << endl;
				} else {
					cout << v << endl;
				}
				pq.pop();
			}
		}
	}
}
