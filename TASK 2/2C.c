#include <stdio.h>
void merge(int* nums1, int m, int* nums2, int n) {
int i = m- 1;
int j = n- 1;
int k = m +n-1;
while (i >= 0 && j >= 0) {
if (nums1[i] > nums2[j]) {
nums1[k] = nums1[i];
i--;
} else {
nums1[k] = nums2[j];
j--;
}
k--;
}
while (j >= 0) {
nums1[k] = nums2[j];
j--;
k--;
}
}
int main() {
int nums1[9] = {1, 3, 5, 7, 9}; 
int m = 5;
int nums2[4] = {2, 4, 6, 8}; 
int n = 4;
for (int i = m; i < m + n; i++) {
nums1[i] = 0;
}
printf("Before merge:\n");
for (int i = 0; i < m + n; i++) {
printf("%d ", nums1[i]);
}
printf("\n");
merge(nums1, m, nums2, n);
SSSprintf("After merge:\n");
for (int i = 0; i < m + n; i++) {
printf("%d ", nums1[i]);
}
printf("\n");
return 0;
}

