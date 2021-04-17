// OJ: https://leetcode.com/problems/decompress-run-length-encoded-list/
// Author: github.com/punkfulw
// Time: O(N) where N is the length of the output array.
// Space: O(1)
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans {};
        int size = nums.size();
        for (int i = 0; i < size; i+=2){
            for (int j = 0; j < nums.at(i); j++){
                int p = nums.at(i+1);
                ans.push_back(p);
            }
        }
        return ans;
    }
};
