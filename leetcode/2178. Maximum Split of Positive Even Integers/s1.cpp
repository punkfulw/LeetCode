// OJ: https://leetcode.com/problems/maximum-split-of-positive-even-integers/
// Author: github.com/punkfulw
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    vector<long long> maximumEvenSplit(long long tar) {
        vector<long long> ans;
        if (tar % 2)
            return {};
        for (long long i = 2; i <= tar; tar -= i, i += 2){
            if (tar - i <= i)
                ans.push_back(tar);
            else
                ans.push_back(i);
        }
        return ans;
    }
};
