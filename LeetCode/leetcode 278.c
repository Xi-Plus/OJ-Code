#include <stdio.h>

int badVersion;
int isBadVersion(int version) {
	printf("checking %d\n", version);
	if (version < badVersion) {
		return 0;
	}
	return 1;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
	long long i = 1, j = n, m;
	while (i <= j) {
		m = (i + j) / 2;
		if (isBadVersion(m)) {
			j = m - 1;
		} else {
			i = m + 1;
		}
	}
	return i;
}

int main() {
	badVersion = 4;
	printf("%d\n", firstBadVersion(5));
	badVersion = 2;
	printf("%d\n", firstBadVersion(3));
}
