int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);

    if (len == 0) {
        return 0;
    }

    int ascii_map[128] = {0}; 

    int left = 0;
    int max_substr_len = 0;
    int substr_len = 1;

    for (int right = 0; right < len; right++) {
        while (ascii_map[(unsigned int)s[right]] > 0) {
            // Shrink the window from the left
            ascii_map[(unsigned int)s[left]]--;
            left++;
        }

        ascii_map[(unsigned int)s[right]]++;

        substr_len = right - left + 1;

        if (substr_len > max_substr_len) {
            max_substr_len = substr_len;
        }
    }

    return max_substr_len;
}
