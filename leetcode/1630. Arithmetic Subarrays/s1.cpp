// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(N*M*logN)
// Space: O(N)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans;
        
        for (int i = 0; i < m; i++){
            bool found = true;
            int left = l[i], right = r[i];
            vector<int> cur(nums.begin() + left, nums.begin() + right + 1);
            sort(cur.begin(), cur.end());

            int dif = cur[1] - cur[0];
            for (int j = 1; j < cur.size() && found; j++)
                if (dif != cur[j] - cur[j - 1])
                    found = false;

            ans.push_back(found);
        } 
        return ans;
    }
};
