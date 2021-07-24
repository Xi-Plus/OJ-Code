#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= q; w++) {
			cout << "*";
		}
		cout << "-" << q;
		cout << endl;
	}
}
