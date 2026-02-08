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
	int val = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < a[i]) {
			val += (n - i);
			ans.push_back(val % 10);
			val /= 10;
			j++;
		}
	}
	while (val) {
		ans.push_back(val % 10);
		val /= 10;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << endl;
}
