// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	priority_queue<int, vector<int>, greater<int>> pq;
	int t, x;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			pq.push(x);
		} else {
			if (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
	}
}
