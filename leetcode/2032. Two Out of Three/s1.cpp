// OJ: https://leetcode.com/problems/two-out-of-three/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& num1, vector<int>& num2, vector<int>& num3) {
        int mp[101] = {};
        set<int> nums1(num1.begin(), num1.end()), nums2(num2.begin(), num2.end()), nums3(num3.begin(), num3.end());
        vector<int> ans;
        for (auto &i: nums1)
            mp[i]++;
        for (auto &i: nums2)
            mp[i]++;
        for (auto &i: nums3)
            mp[i]++;
        for (int i = 1; i <= 100; i++)
            if (mp[i] >= 2)
                ans.push_back(i);
        return ans;
    }
};
