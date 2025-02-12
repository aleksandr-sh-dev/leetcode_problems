int searchInsert(int* nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1, mid;

    while (low <= high) {
        mid = (high + low) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    
    return low;
}
