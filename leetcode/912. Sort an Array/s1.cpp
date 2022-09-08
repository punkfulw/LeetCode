// OJ: https://leetcode.com/problems/sort-an-array/
// Author: github.com/punkfulw
// Time: O(N + K) 
// Space: O(K) 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int idx = 0, offset = 5 * 1e4;
        vector<int> bucket(1e5 + 2);
        for (auto i: nums)
            bucket[i + offset]++;

        for (int i = 0; i < 1e5 + 2; i++){
            while (bucket[i]){
                nums[idx++] = i - offset;
                bucket[i]--;
            }
        }
        return nums;
    }
};
