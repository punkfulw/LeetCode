// OJ: https://leetcode.com/problems/design-front-middle-back-queue/
// Author: github.com/punkfulw
// Time: O(N^2) 
// Space: O(N)
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}
    
    vector<int> nums;

    void pushFront(int val) {
        nums.insert(nums.begin(), val);
    }
    
    void pushMiddle(int val) {
        int pos = nums.size() / 2;
        nums.insert(nums.begin() + pos, val);
    }
    
    void pushBack(int val) {
        nums.push_back(val);
    }
    
    int popFront() {
        if (nums.empty())
            return -1;
        int ret = nums[0];
        nums.erase(nums.begin());
        return ret;
    }
    
    int popMiddle() {
        if (nums.empty())
            return -1;
        int sz = nums.size();
        int pos = sz % 2 ? sz / 2 : sz / 2 - 1;
        int ret = nums[pos];
        nums.erase(nums.begin() + pos);
        return ret;
    }
    
    int popBack() {
        if (nums.empty())
            return -1;
        int ret = nums.back();
        nums.pop_back();
        return ret;
    }
};
