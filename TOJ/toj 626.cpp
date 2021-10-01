#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n / 2; i++) {
		cout << v[n - 1 - i] << " " << v[i];
		if (i < n / 2 - 1) {
			cout << " ";
		}
	}
	if (n % 2 == 1) {
		cout << " " << v[n / 2];
	}
	cout << endl;
}
