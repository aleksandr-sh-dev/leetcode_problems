int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int arr_len = numsSize * 2;
    int *res = calloc(arr_len, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        res[i] = nums[i];
        res[i + numsSize] = nums[i];
    }

    *returnSize = arr_len;

    return res;
}