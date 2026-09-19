// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int a[4];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a, a + 4);
	cout << a[1] << endl;
	for (int i = 3; i < n; i++) {
		cin >> a[0];
		sort(a, a + 4);
		cout << a[1] << endl;
	}
}
