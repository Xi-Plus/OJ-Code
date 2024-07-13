// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	string str;
	while (n--) {
		stack<char> s;
		getline(cin, str);
		for (auto c : str) {
			if (s.empty()) {
				s.push(c);
			} else {
				if (s.top() == '[' && c == ']') {
					s.pop();
				} else if (s.top() == '(' && c == ')') {
					s.pop();
				} else {
					s.push(c);
				}
			}
		}
		if (s.empty()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}
