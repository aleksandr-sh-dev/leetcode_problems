bool is_string_palindrome(char* s, int len, bool deleted_character) {
    int left = 0;
    int right = len - 1;
    int saved_left = 0;
    int saved_right = 0;
    int passed_char = 0;

    while (left < right) {
        if (s[left] != s[right]) {
            if (passed_char == 0) {
                saved_left = left;
                saved_right = right;

                passed_char++;
                right--;
            } else if (passed_char == 1) {
                left = saved_left;
                right = saved_right;

                passed_char++;
                left++;
            } else {
                return false;
            }
        } else {          
            left++;
            right--;
        }
    }

    return true;
}

bool validPalindrome(char* s) {
    int len = strlen(s);
    if (len == 1 || len == 2) {
        return true;
    }

    return is_string_palindrome(s, len, false);
}