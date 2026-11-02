#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> res(2); // this is could be only 2 elemenents at most that appear more then n/3 times
        res.clear();

        int len = nums.size();

        int candidate_1 = 0;
        int counter_1 = 0;

        int candidate_2 = 0;
        int counter_2 = 0;

        // Get two candidates
        for (int i = 0; i < len; i++) {
            if (nums.at(i) == candidate_1) {
                counter_1++;
            } else if (nums.at(i) == candidate_2) {
                counter_2++;
            } else if (counter_1 == 0) {
                candidate_1 = nums.at(i);
                counter_1 = 1;
            } else if (counter_2 == 0) {
                candidate_2 = nums.at(i);
                counter_2 = 1;
            } else {
                counter_1--;
                counter_2--;
            }
        }

        counter_1 = 0;
        counter_2 = 0;

        // Check actual appearance count of each candidate
        for (int i = 0; i < len; i++) {
            if (nums.at(i) == candidate_1) {
                counter_1++;
            } else if (nums.at(i) == candidate_2) {
                counter_2++;
            }
        }

        if (counter_1 > (len / 3)) {
            res.push_back(candidate_1);
        }
        
        if (counter_2 > (len / 3)) {
            res.push_back(candidate_2);
        }

        return res;
    }
};