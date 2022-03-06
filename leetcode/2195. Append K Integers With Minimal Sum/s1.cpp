// OJ: https://leetcode.com/problems/append-k-integers-with-minimal-sum/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/2195.%20Append%20K%20Integers%20With%20Minimal%20Sum/README.md
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        long long ans = 0, n = nums.size();
        
        for (int i = 0; i < n && k; i++)
        {
            long long prev = i == 0 ? 0 : nums[i-1], cur = nums[i];
            long long between = min((long long)k, max((long long)0, cur - prev - 1));
            k -= between;
            ans += (prev + 1 + prev + between) * between / 2;
        }
        return ans;
    }
};
