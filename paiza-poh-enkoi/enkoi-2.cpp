#include <iostream>
using namespace std;
int main(void) {
	int n, ans = 0, t, s, p;
	cin >> n;
	while (n--) {
		cin >> t >> s >> p;
		if (t > s) {
			ans += (t - s) * p;
		}
	}
	cout << ans << endl;
	return 0;
}
