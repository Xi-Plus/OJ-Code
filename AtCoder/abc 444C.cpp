// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> ans;
	int j = n - 1;
	while (a[j] == a[n - 1] && j >= 0) {
		j--;
	}
	if (j == -1) {
		ans.push_back(a[n - 1]);
	}
	int i = 0;
	while (i < j) {
		if (a[i] + a[j] != a[n - 1]) {
			break;
		}
		if (i == j - 1) {
			ans.push_back(a[n - 1]);
		}
		i++;
		j--;
	}
	i = 0;
	j = n - 1;
	int val = a[0] + a[n - 1];
	while (i < j) {
		if (a[i] + a[j] != val) {
			break;
		}
		if (i == j - 1) {
			ans.push_back(val);
		}
		i++;
		j--;
	}
	for (auto v : ans) {
		cout << v << " ";
	}
	cout << endl;
}
