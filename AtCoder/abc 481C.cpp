// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	string s;
	map<string, int> id;
	int next = 1;
	while (q--) {
		cin >> s;
		if (!id[s]) {
			id[s] = next;
			next++;
		}
		cout << id[s] << endl;
	}
}
