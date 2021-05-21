// OJ: https://leetcode.com/problems/sort-array-by-increasing-frequency/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> cnt;
        
        for (int i: nums)
            cnt[i]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return cnt[a] == cnt[b] ? a > b : cnt[a] < cnt[b];});
        return nums;
    }
};
