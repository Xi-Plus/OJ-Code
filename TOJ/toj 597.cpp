#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 3, j = 5, k = 7; i + j + k <= n; i += 3, j += 5, k += 7) {
		cout << i << " " << j << " " << k << endl;
	}
}
