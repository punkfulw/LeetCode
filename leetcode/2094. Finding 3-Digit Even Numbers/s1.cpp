// OJ: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Author: github.com/punkfulw
// Time: O(N^3 * log(1000))
// Space: O(N)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        set<int> ans;
        int n = nums.size(); 
        for (int i = 0; i < n; i++){
            if (nums[i] % 2 != 0)
                continue;
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (j == i || j == k || i == k || nums[k] == 0)
                        continue;
                    ans.insert(100 * nums[k] + 10 * nums[j] + nums[i]);
                }
            }
        }
        return vector<int> (ans.begin(), ans.end());
    }
};
