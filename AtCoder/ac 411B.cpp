// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int v[n - 1];
	for (int i = 0; i < n - 1; i++) {
		cin >> v[i];
	}
	cout << v[0];
	for (int i = 1; i < n - 1; i++) {
		v[i] += v[i - 1];
		cout << " " << v[i];
	}
	cout << endl;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << v[j] - v[i - 1] << " ";
			v[j] -= v[i - 1];
		}
		cout << endl;
	}
}
