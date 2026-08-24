int max(int a, int b) {
    return (a > b ? a : b);
}

int rob(int* nums, int numsSize) {
    if (numsSize < 2) {
        return nums[0];
    }

    int dp[numsSize];
    memset(dp, 0, sizeof(int) * numsSize);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(dp[i - 1], (nums[i] + dp[i - 2]));
    }

    return dp[numsSize - 1];
}
