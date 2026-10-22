/**
 * Note: The returned numsay must be malloced, assume caller calls free().
 */
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int* nums, int low, int mid, int high) {
    int left_half = mid - low + 1;
    int right_half = high - mid;

    int left[left_half];
    int right[right_half];

    for (int i = 0; i < left_half; i++) {
        left[i] = nums[low + i];
    }

    for (int i = 0; i < right_half; i++) {
        right[i] = nums[mid + 1 + i];
    }

    int i = 0; // pointer of left subarray
    int j = 0; // pointer of right subarray
    int k = low; // pointer to indexes of original array

    while (i < left_half && j < right_half) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            i++;
        } else {
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    // Fill up what has left, that is guaranteed to be sorted
    while (i < left_half) {
        nums[k] = left[i];
        i++; 
        k++;
    }

    while (j < right_half) {
        nums[k] = right[j];
        j++; 
        k++;
    }
}

void merge_sort(int* nums, int low, int high) {
    if (low < high) {
        int mid = low + ((high - low) / 2);

        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    if (numsSize == 1) {
        return nums;
    }

    if (numsSize == 2) {
        if (nums[0] < nums[1]) {
            return nums;
        } else {
            swap(&nums[0], &nums[1]);
            return nums;
        }
    }

    merge_sort(nums, 0, numsSize - 1);

    return nums;
}