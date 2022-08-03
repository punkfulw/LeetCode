// OJ: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> getStrongest(vector<int>& nums, int k) {
        int n = nums.size(), median;
        nth_element(nums.begin(), nums.begin() + (n - 1) / 2, nums.end());
        median = nums[(n - 1) / 2];
        sort(nums.begin(), nums.end(), [median](int &a, int &b){
            if (abs(a - median) == abs(b - median))
                return a > b;
            return abs(a - median) > abs(b - median);
        });
        return vector<int> (nums.begin(), nums.begin() + k);
    }
};
