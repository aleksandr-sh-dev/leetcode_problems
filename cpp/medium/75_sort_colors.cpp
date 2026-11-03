#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;
        int cur_num = 0;
        int temp = 0;

        while(i <= right) {
            cur_num = nums.at(i);
            if (cur_num == 0) {
                temp = nums.at(left);
                nums.at(left) = cur_num;
                nums.at(i) = temp;
                left++;
                i++;
            } else if (cur_num == 2) {
                temp = nums.at(right);
                nums.at(right) = cur_num;
                nums.at(i) = temp;
                right--;
            } else {
                i++;
            }
        }
    }
};