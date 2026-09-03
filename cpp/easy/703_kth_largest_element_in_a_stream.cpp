#include <iostream>
#include <queue>

using namespace std;

class KthLargest {
public:
    std::priority_queue<int, vector<int>, greater<int>> minHeap;
    int index;

    KthLargest(int k, vector<int>& nums) {
        index = k;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > index) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
