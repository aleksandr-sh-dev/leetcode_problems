class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_size = nums.size();
        vector<int> res(nums_size);

        for (int i = 0; i < nums_size; i++) {
            int new_idx = i + k;
            while (new_idx >= nums_size) {
                new_idx = new_idx - nums_size;
            }

            res[new_idx] = nums[i];
        }

        nums = res;
    }
};