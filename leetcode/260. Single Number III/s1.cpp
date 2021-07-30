// OJ: https://leetcode.com/problems/single-number-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(S) S = set size
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)
            return {nums[0], nums[1]};
        unordered_set<int> st;
        
        for (int i: nums){
            if (st.count(i))
                st.erase(i);
            else
                st.insert(i);
        }
        vector<int> ans;
        for(auto i: st)
            ans.push_back(i);
        return ans;
    }
};
