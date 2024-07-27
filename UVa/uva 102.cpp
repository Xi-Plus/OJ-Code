// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int arr[3][3];
int pick[][3] = {
	{0, 2, 1},
	{0, 1, 2},
	{2, 0, 1},
	{2, 1, 0},
	{1, 0, 2},
	{1, 2, 0},
};
char name[] = {'B', 'G', 'C'};

int main() {
	// ios::sync_with_stdio(false); cin.tie(0);
	while (cin >> arr[0][0] >> arr[0][1] >> arr[0][2]) {
		for (int q = 1; q < 3; q++) {
			for (int w = 0; w < 3; w++) {
				cin >> arr[q][w];
			}
		}
		int ans = 2e9;
		int ansi = 0;
		for (int q = 0; q < 6; q++) {
			int sum = 0;
			for (int w = 0; w < 3; w++) {
				for (int e = 0; e < 3; e++) {
					if (pick[q][w] != e) {
						sum += arr[w][e];
					}
				}
			}
			if (sum < ans) {
				ans = sum;
				ansi = q;
			}
		}

		for (int q = 0; q < 3; q++) {
			cout << name[pick[ansi][q]];
		}
		cout << ' ' << ans << endl;
	}
}
/*
1 2 3 4 5 6 7 8 9
5 10 5 20 10 5 10 20 10
*/
