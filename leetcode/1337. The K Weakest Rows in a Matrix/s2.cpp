// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(NMlogN)
// Space: O(N)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        set<pair<int, int>> mp;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++){
            int p = 0;
            while (p < m && mat[i][p] == 1)
                p++;
            mp.insert({p, i});
        }
        for (auto it = mp.begin(); k > 0; it++, k--)
            ans.push_back(it->second);
        return ans;
    }
};
