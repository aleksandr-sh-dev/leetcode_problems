/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdint.h>

int comp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) {
        return -1;
    }

    if (x > y) {
        return 1;
    }

    return 0;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 16;
    int **res = malloc(sizeof(int *) * capacity);
    int quadriplets_count = 0;
    qsort(nums, numsSize, sizeof(int), comp);

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int x = nums[i];

        for (int j = i + 1; j < numsSize; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int y = nums[j];
            int64_t sum = (int64_t)target - x - y;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                if ((int64_t)nums[left] + nums[right] == sum) {
                    if (quadriplets_count == capacity) {
                        capacity *=  2;
                        int **tmp = realloc(res, capacity * sizeof(int *));
                        res = tmp;
                    }

                    res[quadriplets_count] = malloc(sizeof(int) * 4);
                    res[quadriplets_count][0] = nums[i];
                    res[quadriplets_count][1] = nums[j];
                    res[quadriplets_count][2] = nums[left];
                    res[quadriplets_count][3] = nums[right];
                    quadriplets_count++;

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if ((int64_t)nums[left] + nums[right] < sum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    int *ret_col_size = malloc(sizeof(int) * quadriplets_count);
    for (int i = 0; i < quadriplets_count; i++) {
        ret_col_size[i] = 4;
    }

    *returnColumnSizes = ret_col_size;
    *returnSize = quadriplets_count;

    return res;
}
