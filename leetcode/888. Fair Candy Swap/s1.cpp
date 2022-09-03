// OJ: https://leetcode.com/problems/fair-candy-swap/
// Author: github.com/punkfulw
// Time: O(A+B)
// Space: O(A)
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int a = accumulate(A.begin(), A.end(), 0), b = accumulate(B.begin(), B.end(), 0), dif = a - b; 
        unordered_map<int, int> mp;
        for (int i: A)
            mp[i]++;
 
        for (auto x: B){
            int tar = x + dif / 2;
            if (mp[tar])
                return {tar, x};
        }
        return {};
    }
};
