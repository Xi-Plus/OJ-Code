// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& v : a) {
		cin >> v;
	}
	int x;
	cin >> x;
	cout << a[x - 1] << endl;
}
