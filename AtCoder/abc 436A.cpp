// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n - s.size(); i++) {
		cout << 'o';
	}
	cout << s << endl;
}
