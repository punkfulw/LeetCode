// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(), neg[2] = {1000, 1000}, pos[3] = {-1000, -1000, -1000};
        
        for (auto &i: nums){
            if (i < neg[1]){
                neg[1] = i;
                if (neg[0] > neg[1])
                    swap(neg[0], neg[1]);
            }
            if (i > pos[2]){
                pos[2] = i;
                if (pos[1] < pos[2])
                    swap(pos[1], pos[2]);
                if (pos[0] < pos[1])
                    swap(pos[0], pos[1]);
            }
        }
        return max(pos[0] * neg[0] * neg[1], pos[0] * pos[1] * pos[2]);
    }
};
