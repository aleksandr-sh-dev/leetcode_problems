#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    if (nums == NULL) {
        return -1;
    }

    if (numsSize == 1) {
        if (nums[0] == target) {
            return 0;
        } else {
            return -1;
        }
    }

    int left, middle = 0; // left index
    int right = numsSize - 1; // right index

    while (left <= right) {
        middle = (left + right) / 2;
        printf("Middle: %d\r\n", middle);
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}
