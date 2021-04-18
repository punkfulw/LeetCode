// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/punkfulw
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size();
        int ans = accumulate(arr.begin(), arr.end(), 0);

        for (int i = 0; i < size; i++){
            if (i + 2 > size)
                break;
            int j = i + 2;
            while (j < size){
                for (int u = i; u <= j; u++){
                    ans += arr[u];
                }
                j += 2;
            }
        }
        return ans;
    }
};
