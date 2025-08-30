// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<string> name(n);
	for (int i = 0; i < n; i++) {
		cin >> name[i];
	}
	int x;
	string y;
	cin >> x >> y;
	if (name[x - 1] == y) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
