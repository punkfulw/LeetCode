// OJ: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Author: github.com/punkfulw
// Reference:https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/discuss/534631/C%2B%2B-beats-100-with-__builtin_popcount
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
     static bool compare(const int &a, const int &b){
         int c1 = __builtin_popcount(a);
         int c2 = __builtin_popcount(b);
         
         if (c1 == c2)
             return a < b;
         return c1 < c2;
     }
};
