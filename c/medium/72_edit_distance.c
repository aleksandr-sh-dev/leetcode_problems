#include <stdio.h>
#include <stdlib.h>

int smallest_of_three(int first, int second, int third) {
    if (first <= second && first <= third) {
        return first;
    } else if (second <= first && second <= third) {
        return second;
    } else {
        return third;
    }

    return 0;
}

int minDistance(char* word1, char* word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);

    if (word2_len == 0) {
        // Need to delete word1_len characters
        return word1_len;
    }

    if (word1_len == 0) {
        // Need to add word2_len characters
        return word2_len;
    }

    int dp[word1_len + 1][word2_len + 1];
    memset(dp, 0, sizeof(dp));

    // i and j represents positions in matrix
    for (int i = 0; i < word1_len + 1; i++) {
        for (int j = 0; j < word2_len + 1; j++) {
            if (i == 0) {
                dp[i][j] = j;
                continue;
            } else if (j == 0) {
                dp[i][j] = i;
                continue;
            }

            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Diagonal
            } else {
                // Calculate the smallest amount of steps among three operations: delete, change, add
                dp[i][j] = smallest_of_three(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[word1_len][word2_len];
}
