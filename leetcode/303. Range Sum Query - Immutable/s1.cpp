// OJ: https://leetcode.com/problems/range-sum-query-immutable/
// Author: github.com/punkfulw
// Time: O(N) for build partial_sum
         O(1) for calling SumRange
// Space: O(N)
class NumArray {
public:
    vector<int> cnt;
    NumArray(vector<int>& nums) : cnt(nums.size()+1, 0){
        partial_sum(nums.begin(), nums.end(), cnt.begin()+1);
    }
    
    int sumRange(int left, int right) {
        return cnt[right+1] - cnt[left];
    }
};
