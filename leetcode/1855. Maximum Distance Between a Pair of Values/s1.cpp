// OJ: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(1)
class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0, res = 0;
        int n = A.size();
        int m = B.size();
        
        while (i < n && j < m){
            if (A[i] > B[j]){
                i++;
            }
            else{
                res = max(res, j - i);
                j++;
            }
        }
        return res;
    }
};
