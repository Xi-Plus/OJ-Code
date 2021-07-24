#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 5, j = 7; i <= a || j <= b; i += 5, j += 7) {
		cout << i << " " << j << endl;
	}
}
