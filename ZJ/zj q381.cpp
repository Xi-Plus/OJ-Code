// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<long long> data;
unordered_set<long long> result;
void build(int i, int maxI, long long sum) {
	if (i == maxI) {
		result.insert(sum);
		return;
	}
	build(i + 1, maxI, sum);
	build(i + 1, maxI, sum + data[i]);
}
bool check(int i, int maxI, long long sum) {
	if (i == maxI) {
		return result.find(-sum) != result.end();
	}
	if (check(i + 1, maxI, sum)) return true;
	if (check(i + 1, maxI, sum + data[i])) return true;
	return false;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long a, d, n, start;
	cin >> a >> d >> n;
	start = a - d;
	for (int i = 0; i < n; i++) {
		cin >> a >> d;
		data.push_back(a - d);
	}
	build(0, n / 2, start);
	if (check(n / 2, n, 0)) {
		cout << "1" << endl;
	} else {
		cout << "0" << endl;
	}
}
