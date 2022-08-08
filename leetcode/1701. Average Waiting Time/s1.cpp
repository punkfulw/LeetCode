// OJ: https://leetcode.com/problems/average-waiting-time/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        double time = cus[0][0], ans = 0;
        for (auto c: cus){
            time = max((double)c[0], time) + c[1];
            ans += time - c[0];
        }
        return ans / cus.size();
    }
};
