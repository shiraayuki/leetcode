#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool containsDuplicate(int *nums, int numsSize) {
  // First i sort the array using quick sort. With this state its much easier
  // to check the duplicates because now they would be next to each other.
  qsort(nums, numsSize, sizeof(int), cmp);

  // Now we can just iterate over the array and check if the integer next
  // to it is equal to itself.
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
