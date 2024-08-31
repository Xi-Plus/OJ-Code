// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int v[1005];
int n;

bool compare(int a, int b) {
	if (a % 10 == b % 10) {
		return a > b;
	}
	return a % 10 < b % 10;
}

void bubble_sort() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (!compare(v[j], v[j + 1])) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}

void built_in_sort() {
	sort(v, v + n, compare);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		// bubble_sort();
		built_in_sort();

		cout << v[0];
		for (int i = 1; i < n; i++) {
			cout << " " << v[i];
		}
		cout << endl;
	}
}
/*
7
38 106 98 26 13 46 51
6
1 2 3 4 5 0
5
98 76 12 34 55
6
33 33 88 88 83 38
*/
