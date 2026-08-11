#define UPPERCASE_A_CHAR (65)

int characterReplacement(char* s, int k) {
    int string_len = strlen(s);

    if (string_len == 1) {
        return 1;
    }

    int char_frequency[26] = {0};
    int max_frequency = 0;
    int left = 0;
    int right = 0;
    int max_len = 0;

    while (right < string_len) {
        int current_char = (int)s[right] - UPPERCASE_A_CHAR;
        char_frequency[current_char]++;
        if (char_frequency[current_char] > max_frequency) {
            max_frequency = char_frequency[current_char];
        }

        int window_size = right - left + 1;
        if ((window_size - max_frequency) > k) {
            // Window is not valid
            char_frequency[(int)s[left] - UPPERCASE_A_CHAR]--;
            left++;
        } else {
            // Valid window
            if (max_len < window_size) {
                max_len = window_size;
            }
        }
        right++;
    }

    return max_len;
}
