// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<long long> p10;
long long square_in_range(long long a, long long b) {
	// cout << "check " << a << " " << b << endl;
	if (b < a) {
		return 0;
	}
	long long sqrta = sqrt(a);
	long long sqrtb = sqrt(b);
	if (sqrta * sqrta == a) {
		return sqrtb - sqrta + 1;
	} else {
		return sqrtb - sqrta;
	}
}
long long concat(long long a, long long b) {
	return stoll(to_string(a) + to_string(b));
}
void sol() {
	long long c, d;
	cin >> c >> d;
	long long ans = 0;
	for (int dig = to_string(c).size(); dig <= to_string(c + d).size(); dig++) {
		// cout << "dig " << dig << endl;
		ans += square_in_range(concat(c, p10[dig - 1]), concat(c, p10[dig] - 1));
		// cout << "ans " << ans << endl;
	}
	ans -= square_in_range(concat(c, p10[to_string(c).size() - 1]), concat(c, c));
	ans -= square_in_range(concat(c, c + d) + 1, concat(c, p10[to_string(c + d).size()] - 1));
	cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	long long a = 1;
	for (int i = 1; i <= 19; i++) {
		p10.push_back(a);
		a *= 10;
	}
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
