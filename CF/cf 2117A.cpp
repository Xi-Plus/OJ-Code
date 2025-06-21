// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x, a;
		cin >> n >> x;
		int first1 = -1, last1 = -1;
		for (int q = 0; q < n; q++) {
			cin >> a;
			if (a == 1) {
				if (first1 == -1) {
					first1 = q;
				}
				last1 = q;
			}
		}
		// cout<<first1<<" "<<last1<<endl;
		if (first1 == -1 || x >= last1 - first1+1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
