int min(int a, int b) {
    return (a < b ? a : b);
}

int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize + 2];
    memset(dp, 0, sizeof(int) * (costSize + 2));
    int n = costSize;

    for (int i = n - 1; i > -1; i--) {
        dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }

    return min(dp[0], dp[1]);
}
