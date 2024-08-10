// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int src, dst, num;
	while (cin >> src >> dst >> num) {
		if (num == 0) {
			cout << "0\n";
			continue;
		}
		int dec = 0;
		for (int fac = 1; num > 0; fac *= src) {
			dec += num % 10 * fac;
			num /= 10;
		}
		vector<int> digits;
		while (dec > 0) {
			digits.push_back(dec % dst);
			dec /= dst;
		}
		for (int q = digits.size() - 1; q >= 0; q--) {
			cout << digits[q];
		}
		cout << "\n";
	}
}
