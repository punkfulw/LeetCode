// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    void merge(int l, int m, int r, vector<int> &nums){
        int i = l, j = m + 1, idx = 0;
        vector<int> arr(r - l + 1);
        while (i <= m && j <= r){
            if (nums[i] <= nums[j])
                arr[idx++] = nums[i++];
            else
                arr[idx++] = nums[j++];
        }
        while (i <= m)
            arr[idx++] = nums[i++];
        while (j <= r)
            arr[idx++] = nums[j++];
        for (int i = l; i <= r; i++)
            nums[i] = arr[i - l];
    }
    
    void mergeSort(int l, int r, vector<int> &nums){
        if (l >= r)
            return;
        int m = l + (r - l) / 2;
        mergeSort(l, m, nums);
        mergeSort(m + 1, r, nums);
        merge(l, m, r, nums);
        return;
    } 
    
    vector<int> sortArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        mergeSort(l, r, nums);
        return nums;
    }
};
