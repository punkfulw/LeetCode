// OJ: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;
        for (auto r: bank){
            int cur = count(r.begin(), r.end(), '1');
            if (cur == 0)
                continue;
            ans += cur * prev;
            prev = cur;
        }
        return ans;
    }
};
