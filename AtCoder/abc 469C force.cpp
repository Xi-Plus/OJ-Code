// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> co(n + 1);
	vector<int> cx(n + 1);
	co[0] = s[0] == 'o';
	cx[0] = s[0] == 'x';
	for (int i = 1; i < n; i++) {
		co[i] = co[i - 1] + (s[i] == 'o');
		cx[i] = cx[i - 1] + (s[i] == 'x');
	}
	int i = 0, pos, npos;
	for (; i < n; i++) {
		pos = i;
		int remain = co[pos];
		while (pos < n && remain > 0) {
			npos = pos + remain;
			if (npos >= n) {
				pos = n - 1;
				break;
			}
			remain = 0;
			remain += co[npos] - co[pos];
			pos = npos;
		}
		if (pos >= n - 1) {
			break;
		}
		cout << pos + 1 << endl;
	}
	for (; i < n; i++) {
		cout << n << endl;
	}
}
