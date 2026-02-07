// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 0;; i++) {
		sum += n + i;
		if (sum >= k) {
			cout << i << endl;
			break;
		}
	}
}
