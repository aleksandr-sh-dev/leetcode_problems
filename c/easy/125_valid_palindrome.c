#include <stdbool.h>

#define ASCII_LOWERCASE_UPPERCASE_DIFF (32) // a - A = 32, b - B = 32, etc

inline bool is_symbol_alphanumeric(char symbol) {
    if ((symbol > 47 && symbol < 58) || (symbol > 96 && symbol < 123)) {
        return true;
    }

    return false;
}

inline bool is_symbol_capital(char symbol) {
    if (symbol > 64 && symbol < 91) {
        return true;
    }

    return false;
}

inline int convertToLowercase(char symbol) {
    return (int)(symbol + ASCII_LOWERCASE_UPPERCASE_DIFF);
}

bool isPalindrome(char* s) {
    if (strlen(s) == 1) {
        return true;
    }

    int left = 0;
    int right = strlen(s) - 1;

    int left_symbol = 0;
    int right_symbol = 0;

    bool palindrome = true;

    while (left <= right) {
        if (is_symbol_alphanumeric(s[left])) {
            left_symbol = (int)s[left];
        } else if (is_symbol_capital(s[left])) {
            left_symbol = convertToLowercase(s[left]); // convert uppercase to lowercase
        } else {
            left++;;
            continue;
        }

        if (is_symbol_alphanumeric(s[right])) {
            right_symbol = (int)s[right];
        } else if (is_symbol_capital(s[right])) {
            right_symbol = convertToLowercase(s[right]); // convert uppercase to lowercase
        } else {
            right--;
            continue;
        }

        if(left_symbol != right_symbol) {
            return false;
        } else {
            palindrome = true; // Keep flag true until characters are equal
        }
        
        left++; // Move left pointer to the next position
        right--; // Move right pointer to the previous position;
    }

    return palindrome;
}
