// OJ: https://leetcode.com/problems/largest-values-from-labels/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int ans = 0, n = values.size(), cnt = 0;
        unordered_map<int, int> label_used;
        vector<pair<int, int>> rec(n);
        
        for (int i = 0; i < n; ++i)
            rec[i] = {values[i], labels[i]};
        
        sort(rec.rbegin(), rec.rend());
        
        for (auto &[val, lab]: rec){
            if (cnt == numWanted || label_used[lab] >= useLimit)
                continue;
            label_used[lab]++;
            cnt++;
            ans += val;
        }
        return ans;
    }
};
