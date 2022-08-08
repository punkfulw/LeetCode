// OJ: https://leetcode.com/problems/convert-1d-array-into-2d-array/
// Author: github.com/punkfulw
// Time: O(NM) 
// Space: O(1)
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        int ttl = original.size();
        if (ttl != n * m)
            return {};
        vector<vector<int>> ans(n, vector<int> (m));
        for (int i = 0; i < n * m; i++)
            ans[i / m][i % m] = original[i];
        return ans;
    }
};
