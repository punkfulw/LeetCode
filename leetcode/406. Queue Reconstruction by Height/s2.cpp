// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC%2B%2BJava-Solution
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& P) {
        sort(P.begin(), P.end(), [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> ans;
        for (auto p: P)
            ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};
