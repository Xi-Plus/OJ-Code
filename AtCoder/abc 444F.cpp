// By xiplus
// WA
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void printSet(multiset<int>& s) {
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void sol() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	int maxV = a[(n - 1) / 2];
	// cout << "maxV: " << maxV << endl;
	multiset<int> s;
	for (int i = (n - 1) / 2; i >= 0; i--) {
		// cout << "Add: " << a[i] << endl;
		s.insert(a[i]);
	}
	// printSet(s);
	int val;
	bool remove = (n % 2);
	for (int i = 0; i < m; i++) {
		val = *s.rbegin();
		// cout << "val: " << val << endl;
		s.erase(s.find(val));
		s.insert(val / 2);
		s.insert((val + 1) / 2);
		// printSet(s);
		// cout << "size: " << s.size() << endl;
		if (s.size() > (n + m + 1) / 2) {
			s.erase(s.begin());
		}
		// printSet(s);
		maxV = max(maxV, *s.begin());
		// cout << "maxV: " << maxV << endl;
	}
	cout << maxV << endl;
}
int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
