using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return nums.size() - std::erase(nums, val);;
    }
};