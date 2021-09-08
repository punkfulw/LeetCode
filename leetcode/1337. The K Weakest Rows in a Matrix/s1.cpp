// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(NMlogN)
// Space: O(N)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<vector<int>> mp;
        for (int i = 0; i < mat.size(); i++){
            mp.push_back({i});
            mp[i].push_back(count(mat[i].begin(), mat[i].end(), 1));
        }
        sort(mp.begin(), mp.end(), [](vector<int> &a, vector<int> &b){
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        for (auto p: mp){
            ans.push_back(p[0]);
            if (ans.size() == k)
                break;
        }
        return ans;
    }
};
