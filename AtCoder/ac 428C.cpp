// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q, t;
	cin >> q;
	char c;
	stack<char> s;
	int wc = 0;
	stack<int> removed;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> c;
			wc++;
			if (c == ')' && !s.empty() && s.top() == '(') {
				removed.push(wc);
				s.pop();
			} else {
				s.push(c);
			}
		} else {
			if (!removed.empty() && wc <= removed.top()) {
				removed.pop();
				s.push('(');
			} else {
				s.pop();
			}
			wc--;
		}
		if (s.empty()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
