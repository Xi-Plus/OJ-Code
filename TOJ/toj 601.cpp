#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int q = 1; q <= n; q++) {
		for (int w = 0; w < 5; w++) {
			cout << "*";
		}
		cout << "-" << q;
		cout << endl;
	}
}
