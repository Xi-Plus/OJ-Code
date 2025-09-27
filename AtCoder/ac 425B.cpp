// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, bool> m;
	int x, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == -1) {
			cnt++;
		} else {
			if (m[v[i]] == false) {
				m[v[i]] = true;
				cnt++;
			}
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (m[i] == false) {
			q.push(i);
		}
	}
	if (cnt == n) {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			if (v[i] == -1) {
				cout << q.front() << " ";
				q.pop();
			} else {
				cout << v[i] << " ";
			}
		}
		cout << endl;
	} else {
		cout << "No" << endl;
	}
}
