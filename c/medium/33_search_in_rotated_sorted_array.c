#include <stdbool.h>

int search(int* nums, int numsSize, int target) {
    if (numsSize == 1) {
        return (nums[0] == target ? 0 : -1);
    }

    bool found = false;
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            found = true;
            break;
        } 
        
        if (left == right) {
            break;
        }

        if (nums[mid] < nums[left]) {
           if (nums[mid] < target && nums[right] >= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        } else {
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
                continue;
            }

            if (nums[left] > target) {
                left = mid + 1;
            } else {
                if (nums[mid] < target) {
                    left = mid + 1;   
                } else {
                    right = mid;
                }
            }
        }
    }

    return (found == true ? mid : -1);
}
