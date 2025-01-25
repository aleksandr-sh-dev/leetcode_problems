import shlex
import sys
import time

def is_palindrome(s: str) -> bool:
    reverse = s[::-1]
    return s == reverse

class Solution:
    def longestPalindrome(s: str) -> str:
        if len(s) == 1 or is_palindrome(s) or len(s) == 0:
            return s

        if len(s) == 2:
            if(is_palindrome(s)):
                return s
            else:
                return s[:1]

        substr_longest_len = 1
        substr_len = 0
        symbol_num = 0
        longest_substring = s[0:1]

        for i in range(0, len(s) + 1):
            for j in range(i + 1, len(s) + 1):
                if is_palindrome(s[i:j]):
                    print(f'String: {s[i:j]} i{i} j{j} is palindrome')
                    substr_len = len(s[i:j])
                if substr_len > substr_longest_len:
                    longest_substring = s[i:j]

                    substr_longest_len = len(s[i:j])
                    print(f'Got new substring length {substr_longest_len}')
                    symbol_num = i

        return longest_substring

if __name__ == '__main__':
    start_time = time.time()
    
    cmdline = " ".join(map(shlex.quote, sys.argv[1:]))

    result = Solution.longestPalindrome(cmdline)
    if (result):
        print(f'Longest palindromic substring: {result}\n\r')
    else:
        print("There is no palindromic string!\n\r")

    print("--- %s seconds ---" % (time.time() - start_time))
