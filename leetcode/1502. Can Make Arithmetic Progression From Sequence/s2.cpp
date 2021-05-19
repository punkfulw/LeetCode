// OJ: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/722307/C%2B%2B-oror-Without-Sort-oror-Set-oror-Easy-to-understand
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> s (arr.begin(), arr.end());
        int max = *max_element(arr.begin(), arr.end());
        int min = *min_element(arr.begin(), arr.end());
        int dif = (max - min) / (arr.size()-1);
        for (int i = 1; i < arr.size(); i++){
            if (!s.count(min + i * dif))
                return false;
        }
        return true;
    }
};
