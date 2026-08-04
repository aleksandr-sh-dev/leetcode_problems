int findMin(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    while (left < right) {
        mid = (right + left) / 2; 
        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return nums[left];
}
