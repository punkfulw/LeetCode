// OJ: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(N)
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans, cnt(n + 1);
        int most = 0;
        cnt[rounds[0]]++;
        for (int i = 0; i < rounds.size() - 1; i++){
            int start = rounds[i] + 1, end = rounds[i + 1] + 1;
            for (int j = start; j != end; j++){
                if (j == n + 1)
                    j = 1;
                cnt[j]++;
                most = max(most, cnt[j]);
            }
        }
        
        for (int i = 1; i <= n; ++i)
            if (cnt[i] == most)
                ans.push_back(i);
        return ans;
    }
};
