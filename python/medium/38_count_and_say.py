import argparse


class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'

        count_and_say_str = '1'

        for _ in range(n - 1):
            new_str = ''
            count = 1

            for i in range(len(count_and_say_str)):
                if i == len(count_and_say_str) - 1 or count_and_say_str[i] != count_and_say_str[i + 1]:
                    new_str += f'{count}{count_and_say_str[i]}'
                    count = 1
                else:
                    count += 1
            count_and_say_str = new_str

        return count_and_say_str
                

def main():
    parser = argparse.ArgumentParser(prog='Given a positive integer n, return the nth element of the count-and-say sequence: ' \
                                          'https://leetcode.com/problems/count-and-say')
    parser.add_argument('--num', type=int, required=True,
                        help='Input positive integer from 1 to 30 (e.g. 4)')

    args = parser.parse_args()
    print(f'n = {args.num}')

    solution = Solution()
    result = solution.countAndSay(args.num)

    print(f'Count and Say of {args.num} is {result}')


if __name__ == "__main__":
    main()