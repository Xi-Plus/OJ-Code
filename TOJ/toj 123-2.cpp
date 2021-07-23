#include <bits/stdc++.h>
int main() {
	char a[200010];
	scanf("%d", (int*)&a[200005]);
	scanf("%s %s", &a[1], &a[*(int*)&a[200005] + 3]);
	a[0] = a[*(int*)&a[200005] + 1] = a[*(int*)&a[200005] + 2] = a[*(int*)&a[200005] * 2 + 3] = '1';  // padding
	for (int i = 0; i < *(int*)&a[200005] * 2 + 4; i++) {
		a[i] -= '0';
	}
	bool ok = true;
	for (int i = 1; i <= *(int*)&a[200005]; i++) {
		ok &= (a[i] | (a[i + *(int*)&a[200005] + 1] & a[i + *(int*)&a[200005] + 2] & a[i + *(int*)&a[200005] + 3]));
	}
	std::cout << (ok ? "FENDED OFF!" : "FENESTRATION FORTIFICATION FAILURE!") << std::endl;
}
