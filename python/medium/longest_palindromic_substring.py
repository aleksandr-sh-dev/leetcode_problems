import shlex
import sys
import time
import argparse

class Solution_slow:
    def longestPalindrome_slow(s: str) -> str:
        def is_palindrome(s: str) -> bool:
            reverse = s[::-1]
            return s == reverse

        if len(s) == 1 or is_palindrome(s) or len(s) == 0:
            return s

        if len(s) == 2:
            if(is_palindrome(s)):
                return s
            else:
                return s[:1]

        substr_longest_len = 1
        substr_len = 1
        longest_substring = s[0:1]

        for i in range(0, len(s) + 1):
            for j in range(i + 2, len(s) + 1):
                if is_palindrome(s[i:j]):
                    print(f'String: {s[i:j]} i{i} j{j} is palindrome')
                    substr_len = len(s[i:j])
                if substr_len > substr_longest_len:
                    longest_substring = s[i:j]

                    substr_longest_len = len(s[i:j])
                    print(f'Got new substring length {substr_longest_len}')

        return longest_substring
    

class Solution:
    def longestPalindrome(s: str) -> str:
        n = len(s)

        def expand_around_center(left, right):
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            
            return right - left - 1

        start = 0
        end = 0
        for i in range(n):
            odd = expand_around_center(i, i)
            even = expand_around_center(i, i + 1)

            max_len = max(odd, even)
            if end - start < max_len:
                start = i - (max_len - 1) // 2
                end = i + max_len // 2

        return s[start: end + 1]

def main():
    start_time = time.time()

    parser = argparse.ArgumentParser(
        prog='Longest Palindromic Substring problem: https://leetcode.com/problems/longest-palindromic-substring',
        description='Two problem solutions: O(n³) and O(n)',
    )

    parser.add_argument('--complexity', type=str, required=True, choices=['O(n2)', 'O(n3)'],
                        help='Time complexity of the solution: O(n2) or O(n3)')
    parser.add_argument('--string', type=str, required=True,
                        help='Input string to find the longest palindromic substring')
    
    args = parser.parse_args()

    input_string = args.string

    if args.complexity == 'O(n2)':
        result = Solution.longestPalindrome(input_string)
    elif args.complexity == 'O(n3)':
        result = Solution_slow.longestPalindrome_slow(input_string)

    if (result):
        print(f'Longest palindromic substring: {result}\n\r')
    else:
        print("There is no palindromic string!\n\r")

    print("--- %s seconds ---" % (time.time() - start_time))

if __name__ == "__main__":
    main()