// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s = "";
	cin >> n;
	char c;
	long long l;
	while (n--) {
		cin >> c >> l;
		if (s.size() + l > 100) {
			cout << "Too Long" << endl;
			return 0;
		}
		for (int i = 0; i < l; i++) s += c;
	}
	cout << s << endl;
}
