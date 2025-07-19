// By xiplus
#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, a;
	map<int, int> m;
	cin >> n;
	while (n--) {
		cin >> a;
		m[a % 1000 / 10]++;
	}
	for (auto it : m) {
		cout << it.first << " " << it.second << endl;
	}
}
