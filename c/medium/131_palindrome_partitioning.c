/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>

bool is_palindrome(char *str, int len) {
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

void backtrack(char ****palindromes, int *palindromes_idx, char ***cur_array, int *cur_array_idx, int **cur_arrays_sizes, char* str, int s_len, int start) {
    if (start == s_len) {
        int strings_num = (*cur_array_idx);
        char **new_array = malloc(sizeof(char *) * strings_num);
        memcpy(new_array, (*cur_array), sizeof(char *) * strings_num);
        (*cur_arrays_sizes)[*palindromes_idx] = strings_num;
        (*palindromes)[*palindromes_idx] = new_array;
        (*palindromes_idx)++;
    }

    for (int i = start; i < s_len; i++) {
        int cur_len = i - start + 1;
        if (is_palindrome(str + start, cur_len)) {
            char *new_str = malloc(sizeof(char) * (cur_len + 1));
            memcpy(new_str, &str[start], cur_len);
            new_str[cur_len] = '\0';
            (*cur_array)[*cur_array_idx] = new_str;
            (*cur_array_idx)++;
            backtrack(palindromes, palindromes_idx, cur_array, cur_array_idx, cur_arrays_sizes, str, s_len, i + 1);
            (*cur_array_idx)--;
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int s_len = strlen(s);
    int capacity = pow(2, s_len - 1);
    char ***palindromes = malloc(sizeof(char **) * capacity);
    int palindromes_idx = 0;
    char **cur_array = malloc(sizeof(char *) * s_len);
    int *cur_arrays_sizes = malloc(sizeof(int) * capacity);
    int cur_array_idx = 0;

    backtrack(&palindromes, &palindromes_idx, &cur_array, &cur_array_idx, &cur_arrays_sizes, s, s_len, 0);

    int *ret_col_size = malloc(sizeof(int) * palindromes_idx);
    for (int i = 0; i < palindromes_idx; i++) {
        ret_col_size[i] = cur_arrays_sizes[i];        
    }

    *returnSize = palindromes_idx;
    *returnColumnSizes = ret_col_size;

    return palindromes;
}
