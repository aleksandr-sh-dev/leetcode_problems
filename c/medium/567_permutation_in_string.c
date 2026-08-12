#include <stdbool.h>

bool checkInclusion(char* s1, char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int s1_chars[26] = {0};
    
    // Calculate num of chars in first string
    for (int i = 0; i < s1_len; i++) {
        int cur_char = (int)s1[i] - 'a';
        s1_chars[cur_char]++;
    }

    int s2_chars[26] = {0};
    int size_chars = sizeof(s1_chars);

    int left = 0;
    int right = 0;

    while (right < s2_len) {
        s2_chars[(int)s2[right] - 'a']++;
        int window_size = right - left + 1;

        if (window_size > s1_len) {
            s2_chars[(int)s2[left] - 'a']--;
            left++;
        }

        if (memcmp(s2_chars, s1_chars, size_chars) == 0) {
            return true;
        }

        right++;
    }

    return false;
}
