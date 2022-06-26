// OJ: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScore(vector<int>& C, int k) {
        int n = C.size(), sum = accumulate(C.begin(), C.end(), 0);
        int e = n - k, mn = INT_MAX, running = 0;
        
        for (int i = 0; i < n; i++){
            running += C[i];
            if (i >= e)
                running -= C[i - e];
            if (i >= e - 1)
                mn = min(mn, running);
        }
        return n == k ? sum : sum - mn;
    }
};
