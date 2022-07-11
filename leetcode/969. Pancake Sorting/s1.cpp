// OJ: https://leetcode.com/problems/pancake-sorting
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> ans;
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        while (nums != arr){
            auto it = max_element(arr.begin(), arr.end()) + 1;
            ans.push_back(it - arr.begin());
            ans.push_back(arr.size());
            reverse(arr.begin(), it);
            reverse(arr.begin(), arr.end());
            arr.pop_back();
            nums.pop_back();
        }
        return ans;
    }
};
