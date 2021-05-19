// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] > arr[i+1])
                return i;
        }
        return 0;
    }
};
