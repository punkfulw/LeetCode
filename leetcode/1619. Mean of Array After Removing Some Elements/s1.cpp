// OJ: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size() * 0.05;
        for (int i = 0; i < n; i++){
            arr.erase(max_element(arr.begin(), arr.end()));
            arr.erase(min_element(arr.begin(), arr.end()));
        }
        return double(accumulate(arr.begin(), arr.end(), 0)) / arr.size();
    }
};
