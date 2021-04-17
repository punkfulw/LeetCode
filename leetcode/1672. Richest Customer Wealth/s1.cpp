// OJ: https://leetcode.com/problems/richest-customer-wealth/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max {};
        for (int i = 0; i < accounts.size(); i++){
            int sum {};
            for (int j = 0; j < accounts[i].size(); j++){
                sum += accounts[i].at(j);
            }
            if (sum > max)
                max = sum;
        }
        return max;
    }
};
