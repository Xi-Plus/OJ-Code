// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	string tmpstr;
	int tmpint;
	while (getline(cin, tmpstr)) {
		stringstream css(tmpstr);
		vector<int> c;
		while (css >> tmpint) {
			c.push_back(tmpint);
		}
		getline(cin, tmpstr);
		stringstream input(tmpstr);
		bool first = true;
		while (input >> tmpint) {
			int ans = 0;
			for (int i = 0; i < c.size(); i++) {
				ans *= tmpint;
				ans += c[i];
			}
			if (first) {
				first = false;
			} else {
				cout << " ";
			}
			cout << ans;
		}
		cout << endl;
	}
}
/*
-2
5 0 1 6
1 -1
7 6 -1
*/
