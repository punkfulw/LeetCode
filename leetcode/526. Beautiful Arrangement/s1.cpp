// OJ: https://leetcode.com/problems/beautiful-arrangement/
// Author: github.com/punkfulw
// Time: O(K) where K is the number of valid permuataions
// Space: O(N)
class Solution {
public:
    int ans = 0;
    void dfs(vector<int> &nums, int idx, int n){
        if (idx == n + 1){
            ans++;  
            return;
        }
        for (int i = 1; i <= n; i++){
            if (nums[i-1] != 0 || (idx % i != 0 && i % idx != 0))
                continue;
            nums[i-1] = idx;
            dfs(nums, idx + 1, n);
            nums[i-1] = 0;
        }
    }
    int countArrangement(int n) {
        vector<int> nums(n);
        dfs(nums, 1, n);
        return ans;
    }
};
