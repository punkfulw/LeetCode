// OJ: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int one = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int mx = one, cntz = 0;
        vector<int> ans;
        ans.push_back(0);
        
        for (int i = 0; i < n; i++){
            cntz += nums[i] == 0;
            one -= nums[i] == 1;
            
            if (cntz + one >= mx){
                if (cntz + one > mx)
                    ans.clear();
                ans.push_back(i + 1);
                mx = cntz + one;
            }    
        }
        return ans;  
    }
};
