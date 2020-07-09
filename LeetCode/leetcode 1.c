#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	*returnSize = 2;
	int* ans = malloc((*returnSize) * sizeof(int));
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				ans[0] = i;
				ans[1] = j;
				return ans;
			}
		}
	}
	return ans;
}

int main() {
	int numbers[4] = {2, 7, 11, 15};
	int returnSize = -1;
	int* ans = twoSum(numbers, 4, 9, &returnSize);
	printf("%d %d\n", ans[0], ans[1]);

	free(ans);
}
