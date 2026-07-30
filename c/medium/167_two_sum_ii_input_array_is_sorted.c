/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *result = calloc(2, sizeof(int));
    *returnSize = 2;

    if (numbersSize == 2) {
        result[0] = 1;
        result[1] = 2;
        return result;
    }

    int right = numbersSize - 1;
    int left = 0;
    
    while(left <= right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            break;
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }

    return result;
}
