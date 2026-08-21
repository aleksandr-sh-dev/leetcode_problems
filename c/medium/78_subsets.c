/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void append(int *cur_path, int cur_path_len, int value) {
    cur_path[cur_path_len] = value;
}

void backtrack(int ***res, int **res_size, int *res_idx, int **cur_path, int cur_path_len, int **nums, int numsSize, int start) {
    int *new_arr = malloc(sizeof(int) * cur_path_len);
    memcpy(new_arr, (*cur_path), sizeof(int) * cur_path_len);
    (*res)[*res_idx] = new_arr;
    (*res_size)[*res_idx] = cur_path_len;
    (*res_idx)++;

    for (int i = start; i < numsSize; i++) {
        append((*cur_path), cur_path_len, (*nums)[i]);
        backtrack(res, res_size, res_idx, cur_path, cur_path_len + 1, nums, numsSize, i + 1);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = pow(2, numsSize);
    int **res = malloc(sizeof(int *) * capacity);
    int *cur_path = malloc(sizeof(int) * numsSize);
    int *res_size = malloc(sizeof(int) * capacity);
    int *res_idx = malloc(sizeof(int));
    res_idx[0] = 0;

    for (int i = 0; i < capacity; i++) {
        // Allocate 1 byte for each subarray
        res[i] = malloc(sizeof(int));
        res_size[i] = 1;
    }

    backtrack(&res, &res_size, res_idx, &cur_path, 0, &nums, numsSize, 0);

    int *ret_col_size = malloc(sizeof(int) * capacity);
    for (int i = 0; i < capacity; i++) {
        ret_col_size[i] = res_size[i];
    }

    *returnSize = capacity;
    *returnColumnSizes = ret_col_size;

    return res;
}
