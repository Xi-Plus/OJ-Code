// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q, act, k, i;
	int a[2] = {1, 1};
	int b[2] = {0, 0};
	char c;
	cin >> Q;
	while (Q--) {
		cin >> act;
		switch (act) {
			case 1:
				cin >> k;
				cout << max(a[0] * k + b[0], a[1] * k + b[1]) << endl;
				break;
			case 2:
				cin >> i >> c >> k;
				switch (c) {
					case '+':
						b[i-1] += k;
						break;
					case '*':
						a[i-1] *= k;
						b[i-1] *= k;
						break;
				}
				break;
			case 3:
				if (a[0] == a[1] || (b[1] - b[0]) % (a[0] - a[1]) != 0) {
					cout << "no" << endl;
				} else {
					cout << (b[1] - b[0]) / (a[0] - a[1]) << endl;
				}
				break;
		}
	}

	return 0;
}
