// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans = {area, 1};
        for (int i = 1; i <= sqrt(area); i++)
            if (area % i == 0)
                if (abs(area / i - i) < abs(ans[1] - ans[0]))
                    ans = {area / i, i};

        return ans;
    }
};
