#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool containsDuplicate(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }
  return false;
}

int main() {
  int nums[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  printf("%b\n", containsDuplicate(nums, 4));

  return 0;
}
