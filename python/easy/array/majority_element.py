import argparse


class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) < 3:
            return nums[0]

        nums.sort()
        size_of_array = len(nums) // 2

        return nums[size_of_array]


def main():
    parser = argparse.ArgumentParser(prog='Majority Element: https://leetcode.com/problems/majority-element')
    parser.add_argument('--array', type=str, required=True,
                        help='Input array of integer numbers (e.g. [2,2,1,1,1,2,2])')

    args = parser.parse_args()
    print(f'Array to find majority element: {args.array}')
    integer_array = list(map(int, args.array.strip("[]").split(",")))

    solution = Solution()
    majority_elemnt = solution.majorityElement(integer_array)

    print(f'Majority element is: {majority_elemnt}')


if __name__ == "__main__":
    main()