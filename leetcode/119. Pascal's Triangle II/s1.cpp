// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> ans = {1, 1};
        if (row == 0)
            return {1};
        dfs(ans, row, 1);
        return ans;
    }
    void dfs(vector<int>& ans, int row, int end){
        vector<int> temp(ans.size() + 1, 1);
        if (row == end)
            return;
        for (int i = 1; i < temp.size()-1; i++)
            temp[i] = ans[i-1] + ans[i];
        end++;
        ans = temp;
        dfs(ans, row, end);
        return;
    } 
};
