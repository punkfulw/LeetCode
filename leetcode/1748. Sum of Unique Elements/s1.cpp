// OJ: https://leetcode.com/problems/sum-of-unique-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans {};
        unordered_map<int, int> m {};
        
        for(int i: nums){
            int cnt = ++m[i];
            ans += cnt == 1 ? i : 0;
            ans += cnt == 2 ? -i : 0;
        }
        return ans;
    }
};
