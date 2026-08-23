#include <stdlib.h>

int expand_around_center(char* s, int left, int right, int s_len) {
    while ((left >= 0 && right < s_len) && (s[left] == s[right])) {
        left--;
        right++;
    }

    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int s_len = strlen(s);

    if (s_len == 1) {
        return s;
    }

    char *longest_palindrome = NULL;
    
    int start_idx = 0;
    int max_len = 0;

    for (int i = 0; i < s_len; i++) {
        int len_odd = expand_around_center(s, i, i, s_len);
        int len_even = expand_around_center(s, i, i + 1, s_len);

        int current_max_len = (len_odd > len_even ? len_odd : len_even);

        if (current_max_len > max_len) {
            max_len = current_max_len;
            start_idx = i - (current_max_len - 1) / 2;
        }
    }

    longest_palindrome = malloc(sizeof(char) * (max_len + 1));
    memcpy(longest_palindrome, &s[start_idx], (max_len + 1));
    longest_palindrome[max_len] = '\0';

    return longest_palindrome;
}
