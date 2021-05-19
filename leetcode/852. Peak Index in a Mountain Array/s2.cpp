// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1 , mid;
        while(l < r){
            mid = (r + l) /2;
            if (arr[mid] < arr[mid+1])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};
