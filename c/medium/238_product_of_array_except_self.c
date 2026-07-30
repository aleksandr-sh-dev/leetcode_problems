/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <unistd.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL) {
        return NULL;
    }

    int *result = malloc(numsSize * sizeof(int));

    if (numsSize == 2) {
        result[0] = nums[1];
        result[1] = nums[0];
        *returnSize = 2;
        return result;
    }

    // Allocated memory for array that holds suffixes
    int *suffix = malloc(numsSize * sizeof(int));
    int *prefix = malloc(numsSize * sizeof(int));

    // Fill array with 1s
    for (int i = 0; i < numsSize; i++) {
        suffix[i] = 1;
        prefix[i] = 1;
    }

    // Calculate suffix array
    for (int i = numsSize - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    result[0] = suffix[0];

    // Calculate product of array except self
    for (int i = 1; i < numsSize; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
        result[i] = prefix[i] * suffix[i];
    }

    *returnSize = numsSize;

    free(suffix);
    free(prefix);

    return result;
}
