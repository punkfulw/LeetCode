// OJ: https://leetcode.com/problems/third-maximum-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;   
        for (auto &i: nums){
            top3.insert(i);
            if (top3.size() > 3)
                top3.erase(top3.begin());
        }
        return top3.size() != 3 ? *top3.rbegin() : *top3.begin();
    }
};
