// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        size_t i = 0;
        size_t j = A.size()-1;
        vector<int> ans = A;
        
        for (int num: A){
            (num % 2) ? ans[j--] = num : ans[i++] = num;
        }
        return ans;        
    }
};
