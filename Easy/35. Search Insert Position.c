struct finder {
    int index;
    bool found_position;
};

int searchInsert(int* nums, int numsSize, int target)
{
    struct finder finder;
    finder.found_position = true;
    finder.index = numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
        if (finder.found_position && nums[i] > target) {
            finder.index = i;
            finder.found_position = false;
        }
    }
    
    return finder.index;
}