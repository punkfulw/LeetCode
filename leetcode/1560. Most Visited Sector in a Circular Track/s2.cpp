// OJ: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/806814/JavaC%2B%2BPython-From-Start-to-End
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        if (rounds[0] <= rounds.back())
            for (int i = rounds[0]; i <= rounds.back(); ++i)
                ans.push_back(i);
        else {
            for (int i = 1; i <= rounds.back(); ++i)
                ans.push_back(i);
            for (int i = rounds[0]; i <= n; ++i)
                ans.push_back(i);
        }
        return ans;
    }
};
