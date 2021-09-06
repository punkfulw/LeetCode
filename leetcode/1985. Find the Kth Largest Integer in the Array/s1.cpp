// OJ: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](string &a, string &b){
            if (a.size() == b.size())
                return a > b;
            return a.size() > b.size();
        });
        return nums[k-1];
    }
};
