// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	vector<int> b(n);
	for (int i = n - 1; i >= 0; i--) {
		if (i + 1 == a[i]) {
			b[i] = i + 1;
		} else {
			b[i] = b[a[i] - 1];
		}
	}
	for (auto& i : b) {
		cout << i << ' ';
	}
	cout << endl;
}
