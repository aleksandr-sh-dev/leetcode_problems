/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define FOUND_NUM_COEFFICIENT (10)

void append(int *cur_arr, int cur_arr_len, int value) {
    cur_arr[cur_arr_len] = value;
}

void backtrack(int ***res, int *res_idx, int *cur_arr, int cur_arr_len, int *nums, int numsSize, int **found_nums, int start) {
    if (cur_arr_len == numsSize) {
        int *new_arr = malloc(sizeof(int) * numsSize);
        memcpy(new_arr, cur_arr, sizeof(int) * numsSize);
        (*res)[*res_idx] = new_arr;
        (*res_idx)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if ((*found_nums)[nums[i] + FOUND_NUM_COEFFICIENT] == 0) {
            append(cur_arr, cur_arr_len, nums[i]);
            (*found_nums)[nums[i] + FOUND_NUM_COEFFICIENT]++;
        } else {
            continue;
        }
        
        backtrack(res, res_idx, cur_arr, cur_arr_len + 1, nums, numsSize, found_nums, i);
        (*found_nums)[nums[i] + FOUND_NUM_COEFFICIENT]--;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 1000;
    int **res = malloc(sizeof(int *) * capacity);
    int *cur_arr = calloc(numsSize, sizeof(int));
    int *found_nums = calloc(21, sizeof(int));
    int res_idx = 0;

    backtrack(&res, &res_idx, cur_arr, 0, nums, numsSize, &found_nums, 0);

    free(found_nums);
    free(cur_arr);
    int *ret_col_size = malloc(sizeof(int) * res_idx);
    for (int i = 0; i < res_idx; i++) {
        ret_col_size[i] = numsSize;
    }

    *returnSize = res_idx;
    *returnColumnSizes = ret_col_size;

    return res;
}
