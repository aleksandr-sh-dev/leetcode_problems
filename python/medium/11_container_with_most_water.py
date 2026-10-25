import argparse
import ast


def string_to_int_list(str):
    return list(ast.literal_eval(str))


class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_area = 0
        lower_idx = 0
        higher_idx = len(height) - 1
        while lower_idx != higher_idx:

            area = min(height[higher_idx], height[lower_idx]) * (higher_idx - lower_idx)
            if area > max_area:
                max_area = area

            if height[higher_idx] > height[lower_idx]:
                lower_idx += 1
            else:
                higher_idx -= 1

        return max_area
                

def main():
    parser = argparse.ArgumentParser(prog='Find two lines that together with the x-axis form a container, such that the container contains the most water.: ' \
                                          'https://leetcode.com/problems/container-with-most-water/')
    parser.add_argument('--array', type=str, required=True,
                        help='Input array of integers to get container with most of water (e.g. [1,8,6,2,5,4,8,3,7])')

    args = parser.parse_args()

    list_of_integers = string_to_int_list(args.array)

    print(f'List of integers {list_of_integers}')

    solution = Solution()
    result = solution.maxArea(list_of_integers)

    print(f'Max area: {result}')


if __name__ == "__main__":
    main()