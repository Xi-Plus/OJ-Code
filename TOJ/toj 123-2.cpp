#include <bits/stdc++.h>
int main() {
	int n;
	std::cin >> n;
	char a[200010] = {'1'};	 //  left padding for first line
	scanf("%s %s", &a[1], &a[n + 3]);
	memset(&a[n + 1], '1', 2);	// right padding for first line and left padding for second line
	a[n * 2 + 3] = '1';			// right padding for second line
	for (int i = 0; i < n * 2 + 4; i++) {
		a[i] -= '0';
	}
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		ok &= (a[i] | (a[i + n + 1] & a[i + n + 2] & a[i + n + 3]));
	}
	std::cout << (ok ? "FENDED OFF!" : "FENESTRATION FORTIFICATION FAILURE!") << std::endl;
}
