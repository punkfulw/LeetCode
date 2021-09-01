// OJ: https://leetcode.com/contest/biweekly-contest-55/problems/maximum-alternating-subsequence-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int flag = 1, n = nums.size();
        for (int i = 0; i < n; i++){
            if (flag % 2){
                while (i < n - 1 && nums[i] < nums[i + 1])
                    i++;
                ans += nums[i];
            }
            else{
                while (i < n - 1 && nums[i] > nums[i + 1])
                    i++;
                if (i == n - 1)
                    break;
                ans -= nums[i];
            }
            flag++;
        }
        return ans;
    }
};
