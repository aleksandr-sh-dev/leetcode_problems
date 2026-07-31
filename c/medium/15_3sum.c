/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <unistd.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= (high - 1); j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort nums in ascending order
    quicksort(nums, 0, numsSize - 1);

    int triplets_num = 0;
    int right = numsSize - 1;
    int capacity = 16;
    int **result = malloc(sizeof(int *) * capacity);

    for (int i = 0; i < numsSize; i++) {
        if (i != 0) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
        }

        int target = nums[i];
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right) {
            if (left == i) {
                left++;
                continue;
            } else if (right == i) {
                right--;
                continue;
            }

            int sum = nums[left] + nums[right];

            if (sum == (-target)) {
                if (triplets_num == capacity) {
                    capacity *= 2;
                    int **temp = realloc(result, capacity * sizeof(int *));
                    if (temp == NULL) {
                        *returnSize = triplets_num;
                        int *ret_col_size = malloc(sizeof(int) * triplets_num);
                        for (int k = 0; k < triplets_num; k++) {
                            ret_col_size[k] = 3;
                        }
                        *returnColumnSizes = ret_col_size;
                        return result;
                    }
                    result = temp;
                }
                triplets_num++;
                result[triplets_num - 1] = malloc(sizeof(int) * 3);
                result[triplets_num - 1][0] = nums[i];
                result[triplets_num - 1][1] = nums[right];
                result[triplets_num - 1][2] = nums[left];

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } else if (sum < (-target)) {
                left++;
            } else {
                right--;
            }
        }
    }

    int *ret_col_size = malloc(sizeof(int) * triplets_num);
    for (int i = 0; i < triplets_num; i++) {
        ret_col_size[i] = 3;
    }

    *returnSize = triplets_num;
    *returnColumnSizes = ret_col_size;

    return result;
}
