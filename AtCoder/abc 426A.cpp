// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string x, y;
	unordered_map<string, int> version = {
		{"Ocelot", 1},
		{"Serval", 2},
		{"Lynx", 3},
	};
	cin >> x >> y;
	if (version[x] >= version[y]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
