#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                return true;
            }

            hash.insert(nums.at(i));

            if (hash.size() > k) {
                hash.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
