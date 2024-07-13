// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, t;
	while (cin >> n && n) {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			q.push(i);
		}
		cout << "Discarded cards:";
		bool first = true;
		while (q.size() > 1) {
			if (first) {
				cout << " " << q.front();
				first = false;
			} else {
				cout << ", " << q.front();
			}
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
	}
}
