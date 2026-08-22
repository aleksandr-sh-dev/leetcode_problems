/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'

int factorial(int n) {
    int fact = 1, i;

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

void append(char *cur_str, int idx, char bracket) {
    cur_str[idx] = bracket;
}

void backtrack(char ***res, int *res_idx, char *cur_str, int cur_str_len, int str_len, int n, int open_count, int closed_count) {
    if (cur_str_len == str_len) {
        char *new_str = malloc(sizeof(char) * (str_len + 1));
        memcpy(new_str, cur_str, sizeof(char) * (str_len + 1));
        new_str[str_len] = '\0';
        (*res)[*res_idx] = new_str;
        (*res_idx)++;
        return;
    }

    if (cur_str_len >= str_len) {
        return;
    }

    if (open_count < n) {
        append(cur_str, cur_str_len, OPEN_BRACKET);
        backtrack(res, res_idx, cur_str, cur_str_len + 1, str_len, n, open_count + 1, closed_count);
    }

    if (closed_count < open_count) {
        append(cur_str, cur_str_len, CLOSE_BRACKET);
        backtrack(res, res_idx, cur_str, cur_str_len + 1, str_len, n, open_count, closed_count + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = factorial(n);
    int str_len = n * 2;
    int res_idx = 0;
    char *cur_str = malloc(sizeof(char) * (str_len + 1));
    char **res = malloc(sizeof(char *) * capacity);

    backtrack(&res, &res_idx, cur_str, 0, str_len, n, 0, 0);

    free(cur_str);
    *returnSize = res_idx;

    return res;
}
