// By xiplus
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		if (a + b < c) {
			cout << 0 << endl;
		} else {
			cout << (a + b - c) / (c - 1) + 1 << endl;
		}
	}
}
