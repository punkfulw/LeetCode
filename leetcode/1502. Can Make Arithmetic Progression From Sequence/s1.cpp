// OJ: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dif = arr[1] - arr[0];
        for (int i = 0; i < arr.size()-1; i++){
            if (arr[i+1] - arr[i] != dif)
                return false;
        }
        return true;
    }
};
