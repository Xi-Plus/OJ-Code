#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
	char cnt[127] = {};
	int unique = 0;
	int size = strlen(s);
	int ans = 0;
	int i = 0, j = 0;
	while (j < size) {
		cnt[s[j]]++;
		if (cnt[s[j]] == 1) {
			unique++;
		}
		j++;
		if (unique == j - i) {
			if (unique > ans) {
				ans = unique;
			}
		} else {
			while (unique != j - i) {
				cnt[s[i]]--;
				if (cnt[s[i]] == 0) {
					unique--;
				}
				i++;
			}
		}
	}
	return ans;
}

int main() {
	char s1[] = "abcabcbb";
	printf("%s %d\n", s1, lengthOfLongestSubstring(s1));
	char s2[] = "bbbbb";
	printf("%s %d\n", s2, lengthOfLongestSubstring(s2));
	char s3[] = "pwwkew";
	printf("%s %d\n", s3, lengthOfLongestSubstring(s3));
}
