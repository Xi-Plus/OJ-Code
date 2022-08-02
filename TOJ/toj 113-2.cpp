#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	char c;
	cin >> n >> s >> c;
	if (c == 'L') {
		cout << s.substr(1) << "." << endl;
	} else {
		cout << "." << s.substr(0, n - 1) << endl;
	}
}
