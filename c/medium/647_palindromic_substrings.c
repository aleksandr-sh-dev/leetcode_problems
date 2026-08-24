int expand_around_center(char *s, int left, int right, int s_len) {
    int substrings_counter = 0;
    while ((left >= 0 && right < s_len) && (s[left] == s[right])) {
        substrings_counter++;
        left--;
        right++;
    }

    return substrings_counter;
}

int countSubstrings(char* s) {
    int s_len = strlen(s);

    if (s_len == 1) {
        return 1;
    }

    int substrings_num = 0;

    for (int i = 0; i < s_len; i++) {
        int num_odd = expand_around_center(s, i, i, s_len);
        int num_even = expand_around_center(s, i, i + 1, s_len);

        substrings_num += num_odd + num_even;
    }

    return substrings_num;
}
