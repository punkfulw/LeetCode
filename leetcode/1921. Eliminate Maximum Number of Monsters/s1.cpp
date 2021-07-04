// OJ: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> cnt(n);
        for (int i = 0; i < n; i++)
            cnt[i] = (double)dist[i] / speed[i];
        
        sort(cnt.begin(), cnt.end());
        for (int i = 1; i < n; i++){
            if (cnt[i] - i <= 0)
                return i;
        }
        return dist.size();
    }
};
