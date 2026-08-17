/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b) {
    const int *row_a = *(const int **)a;
    const int *row_b = *(const int **)b;

    if (row_a[0] < row_b[0]) return -1;
    if (row_a[0] > row_b[0]) return 1;

    return 0;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 1) {
        *returnSize = 1;
        int *size = malloc(sizeof(int) * 1);
        size[0] = 2;
        *returnColumnSizes = size;
        return intervals;
    }

    // Quicksort by the zero index of each interval
    int capacity = 16;
    int num_arrays = 0;
    int **res = malloc(sizeof(int *) * capacity);
    qsort(intervals, intervalsSize, sizeof(intervals[0]), comp);

    int start = -1;
    int current_end = intervals[0][1];

    // Iterate over all intervals swapping them in place if two intervals are overlapping
    for (int i = 0; i < intervalsSize - 1; i++) {
        if (start == -1) {
            start = intervals[i][0];
        }
        if (intervals[i + 1][0] <= current_end) {
            if (current_end < intervals[i + 1][1]) {
                current_end = intervals[i + 1][1];
            }
        } else {
            // Resize array
            if (num_arrays == capacity) {
                capacity *= 2;
                int **tmp = realloc(res, sizeof(int *) * capacity);
                res = tmp;
            }

            res[num_arrays] = malloc(sizeof(int) * 2);
            res[num_arrays][0] = start;
            res[num_arrays][1] = current_end;
            num_arrays++;
            start = intervals[i + 1][0];
            current_end = intervals[i + 1][1];
        }
    }

    res[num_arrays] = malloc(sizeof(int) * 2);
    res[num_arrays][0] = start;
    res[num_arrays][1] = current_end;
    num_arrays++;

    int *size = malloc(sizeof(int) * num_arrays);
    for (int j = 0; j < num_arrays; j++) {
        size[j] = 2;
    }

    *returnColumnSizes = size;
    *returnSize = num_arrays;
    return res;
}
