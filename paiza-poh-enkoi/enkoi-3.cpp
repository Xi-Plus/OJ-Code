#include <iostream>
using namespace std;
int main(void) {
	int t, n;
	cin >> t >> n;
	int arr[n];
	for (int q = 0; q < n; q++) {
		cin >> arr[q];
	}
	int sum = 0;
	for (int q = 0; q < t; q++) {
		sum += arr[q];
	}
	int ans = sum;
	for (int q = t; q < n; q++) {
		sum += arr[q] - arr[q - t];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
