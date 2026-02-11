#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // index for placing non-val elements
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // move non-val element forward
            k++;
        }
    }
    return k; // number of elements not equal to val
}

int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 2;

    int k = removeElement(nums, numsSize, val);

    printf("k = %d\n", k);
    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
