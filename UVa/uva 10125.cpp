// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> data;

int check(int n) {
	for (int d = n - 1; d >= 0; d--) {
		for (int a = 0; a < n; a++) {
			for (int b = a + 1; b < n; b++) {
				for (int c = b + 1; c < n; c++) {
					if (a == d || b == d || c == d) continue;
					if (data[a] + data[b] + data[c] == data[d]) {
						return data[d];
					}
				}
			}
		}
	}
	return 2147483647;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n, n) {
		data.clear();
		data.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		sort(data.begin(), data.end());
		int ans = check(n);
		if (ans == 2147483647) {
			cout << "no solution" << endl;
		} else {
			cout << ans << endl;
		}
	}
}
