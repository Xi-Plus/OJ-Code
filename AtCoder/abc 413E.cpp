// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[262144];
int twopower[19] = {1};

void dfs(int s, int len) {
	if (len == 1) {
		return;
	}
	dfs(s, len / 2);
	dfs(s + len / 2, len / 2);
	bool toSwap = false;
	int half = len / 2;
	for (int i = s; i < s + half; i++) {
		if (a[i] < a[i + half]) {
			break;
		}
		if (a[i] > a[i + half]) {
			toSwap = true;
			break;
		}
	}
	if (toSwap) {
		for (int i = s; i < s + half; i++) {
			swap(a[i], a[i + half]);
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i < 19; i++) {
		twopower[i] = twopower[i - 1] * 2;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < twopower[n]; i++) {
			cin >> a[i];
		}
		dfs(0, twopower[n]);
		for (int i = 0; i < twopower[n]; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
