#include <iostream>
using namespace std;
int main(void) {
	int n, t, ans = 0;
	cin >> n;
	while (n--) {
		cin >> t;
		ans += t;
	}
	cout << ans << endl;
	return 0;
}
