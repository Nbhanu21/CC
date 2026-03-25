#include <stdio.h>S
int removeDuplicates(int* nums, int numsSize) {
if (numsSize == 0) {
return 0;
}
int i = 0; 
for (int j = 1; j < numsSize; j++) {
if (nums[j] != nums[i]) {
i++;
nums[i] = nums[j];
}
}
return i + 1;
}
int main() {
int nums[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 6};
int n = sizeof(nums) / sizeof(nums[0]);
int newLength = removeDuplicates(nums, n);
printf("New length = %d\n", newLength);
printf("Array after removing duplicates: ");
for (int i = 0; i < newLength; i++) {
printf("%d ", nums[i]);
}
printf("\n");
return 0;
}

