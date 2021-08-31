// OJ: https://leetcode.com/problems/random-pick-index/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/random-pick-index/discuss/88071/C%2B%2B_Time%3A-O(n)-Space%3A-O(n)_116ms_96.41_with-clear-explanation-by-probability
// Time: O(N)
// Space: O(N)
class Solution {
    vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = -1;
        for(int i = 0 ; i < _nums.size(); i++){
            if(_nums[i] != target) continue;
            n++;
            if(rand() % n == 0) ans = i;
        }
        return ans;
    }
};
