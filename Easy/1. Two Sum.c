int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *solution = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] + nums[i] == target) {
                printf("\nSolution has been found ");
                solution[0] = i;
                solution[1] = j;
                return solution;
            }
        }
    }
    
    return 0;
}
