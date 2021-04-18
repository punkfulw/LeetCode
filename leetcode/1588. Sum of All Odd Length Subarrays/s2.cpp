// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
// Ref: https://www.youtube.com/watch?v=J5IIH35EBVE
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int N = arr.size();
        int ans {};
        
        for (int i = 0; i < N; i++){
            int end = i + 1;
            int start = N - i;
            int total = end * start;
            int odd = (total + 1) / 2;
            
            ans += arr[i] * odd;
        }
        return ans;
    }
};
