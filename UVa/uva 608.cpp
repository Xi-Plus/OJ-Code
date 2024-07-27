// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string input[3][3];
bool valid(char c, int updown) {
	map<char, int> weight;
	for (char c = 'A'; c <= 'L'; c++) {
		weight[c] = 0;
	}
	weight[c] = updown;
	for (int q = 0; q < 3; q++) {
		int l = 0, r = 0;
		for (auto c : input[q][0]) {
			l += weight[c];
		}
		for (auto c : input[q][1]) {
			r += weight[c];
		}
		if (l == r && input[q][2] != "even") {
			return false;
		}
		if (l < r && input[q][2] != "down") {
			return false;
		}
		if (l > r && input[q][2] != "up") {
			return false;
		}
	}
	return true;
}

void ans() {
	for (char c = 'A'; c <= 'L'; c++) {
		if (valid(c, -1)) {
			cout << c << " is the counterfeit coin and it is light." << endl;
			return;
		}
	}
	for (char c = 'A'; c <= 'L'; c++) {
		if (valid(c, 1)) {
			cout << c << " is the counterfeit coin and it is heavy." << endl;
			return;
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int q = 0; q < 3; q++) {
			for (int w = 0; w < 3; w++) {
				cin >> input[q][w];
			}
		}
		ans();
	}
}
/*
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even
*/
