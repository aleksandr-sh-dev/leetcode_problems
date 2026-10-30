// Boyer–Moore Majority Vote Algorithm 
// (Only Phase 1 because problem description says that there is always a majority element that exists in the array)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums.at(i);
            }

            if (nums.at(i) == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};