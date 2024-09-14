// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	int n, l;
	cin >> n >> l;
	int cut[n + 1], a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cut[b] = a;
	}
	set<int> s;
	s.insert(0);
	s.insert(l);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		s.insert(cut[i]);
		auto prev = s.find(cut[i]);
		auto next = prev;
		prev--;
		next++;
		ans += *next - *prev;
	}
	cout << ans << endl;
}
/*
3 7
2 2
3 1
5 3
*/
