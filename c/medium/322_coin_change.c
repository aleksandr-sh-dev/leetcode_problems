#define MAX_INT 2147483647

int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) {
        return 0;
    }

    if (coinsSize == 1) {
        if (amount == coins[0]) {
            return amount;
        } else if (amount < coins[0]) {
            return -1;
        }

        if (amount % coins[0] == 0) {
            return (amount / coins[0]);
        } else {
            return -1;
        }
    }

    long dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = MAX_INT;
    }

    dp[0] = 0;

    for (int i = 1; i < amount + 1; i++) {
        long min_coin = MAX_INT;
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] == i) {
                min_coin = 1;
                break;
            } else if (coins[j] < i) {
                if (dp[i - coins[j]] != MAX_INT) {
                    long coin = 1 + dp[i - coins[j]];
                    if (coin < min_coin) {
                        min_coin = coin;
                    }
                }
            }
        }

        dp[i] = min_coin;
    }

    if (dp[amount] == MAX_INT) {
        return -1;
    }

    return (int)dp[amount];
}
