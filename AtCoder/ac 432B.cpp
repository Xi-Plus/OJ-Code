// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int x;
	cin >> x;
	vector<int> dig;
	while (x) {
		dig.push_back(x % 10);
		x /= 10;
	}
	sort(dig.begin(), dig.end());
	if (dig[0] == 0) {
		for (int i = 0; i < dig.size(); i++) {
			if (dig[i] != 0) {
				swap(dig[0], dig[i]);
				break;
			}
		}
	}
	for (auto v : dig) {
		cout << v;
	}
	cout << endl;
}
