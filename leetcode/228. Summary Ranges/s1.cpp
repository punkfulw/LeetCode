// OJ: https://leetcode.com/problems/summary-ranges/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string s = "";
        if (nums.size() == 0)
            return ans;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != end + 1){
                s = "";
                s += to_string(start);
                if (end != start)
                    s += "->" + to_string(end);
                start = nums[i];
                ans.push_back(s);
            }
            end = nums[i];
        }
        s = "";
        s += to_string(start);
        if (end != start)
            s += "->" + to_string(end);
        ans.push_back(s);
        return ans;
    }
};
