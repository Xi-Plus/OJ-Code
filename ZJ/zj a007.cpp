// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool nisp[46341] = {false};
int p[10000];
int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
	nisp[0] = nisp[1] = true;
	int i = 2, j, k = 0;
	while (i < 46341) {
		if (!nisp[i]) {
			p[k++] = i;
			j = i * 2;
			while (j < 46341) {
				nisp[j] = true;
				j += i;
			}
		}
		i++;
	}
	int n;
	while (cin >> n) {
		if (n == 2 || n == 3)
			cout << "質數" << endl;
		else if ((n - 1) % 6 && (n + 1) % 6)
			cout << "非質數" << endl;
		else if (n <= 46340) {
			if (binary_search(p, p + k, n))
				cout << "質數" << endl;
			else
				cout << "非質數" << endl;
		} else {
			bool x = 0;
			for (int q = 0; q < k && p[q] * p[q] <= n; q++) {
				if (n % p[q] == 0) {
					x = 1;
					break;
				}
			}
			if (x)
				cout << "非質數" << endl;
			else
				cout << "質數" << endl;
		}
	}
}
