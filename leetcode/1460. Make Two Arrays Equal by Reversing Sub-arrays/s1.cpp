// OJ: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int cnt[1001] = {};
        for (int i: target){
            cnt[i]++;
        }
        for (int i: arr){
            cnt[i]--;
        }
        
        for (int i: cnt){
            if(i != 0)
                return false;
        }
        return true;
    }
};
