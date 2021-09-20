// OJ: https://leetcode.com/problems/best-sightseeing-pair/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int premax = values[0], ans = 0;
        for (int i = 1; i < values.size(); i++){
            ans = max(ans, --premax + values[i]);
            premax = max(premax, values[i]);
        }
        return ans;
    }
};
