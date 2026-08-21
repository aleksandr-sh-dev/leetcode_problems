/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void append(int *cur_arr, int cur_arr_len, int value) {
    cur_arr[cur_arr_len] = value;
}

void backtrack(int ***res, int **res_size, int *res_idx, int *cur_arr, int cur_arr_len, int *capacity, int *candidates, int candidatesSize, int start, int sum, int target) {
    if ((*res_idx) == (*capacity)) {
        (*capacity) *= 2;
        int **tmp = realloc((*res), sizeof(int *) * (*capacity));
        (*res) = tmp;

        int *tmp_size = realloc((*res_size), sizeof(int) * (*capacity));
        (*res_size) = tmp_size;
    }

    if (sum > target) {
        return;
    }

    if (sum == target) {
        int *new_arr = malloc(sizeof(int) * cur_arr_len);
        memcpy(new_arr, cur_arr, sizeof(int) * cur_arr_len);
        (*res)[*res_idx] = new_arr;
        (*res_size)[*res_idx] = cur_arr_len;
        (*res_idx)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        append(cur_arr, cur_arr_len, candidates[i]);
        int new_sum = sum + candidates[i];

        if (new_sum > target) {
            return;
        }

        backtrack(res, res_size, res_idx, cur_arr, cur_arr_len + 1, capacity, candidates, candidatesSize, i, new_sum, target);
    }
}

int comp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 3;
    int **res = malloc(sizeof(int *) * capacity);
    int *res_size = malloc(sizeof(int) * capacity);
    int *res_idx = malloc(sizeof(int));
    *res_idx = 0;
    int *cur_arr = malloc(sizeof(int) * 1000);

    qsort(candidates, candidatesSize, sizeof(candidates[0]), comp);
    backtrack(&res, &res_size, res_idx, cur_arr, 0, &capacity, candidates, candidatesSize, 0, 0, target);

    int *ret_col_size = malloc(sizeof(int) * (*res_idx));
    for (int i = 0; i < (*res_idx); i++) {
        ret_col_size[i] = res_size[i];
    }

    *returnColumnSizes = ret_col_size;
    *returnSize = (*res_idx); 

    return res;
}
