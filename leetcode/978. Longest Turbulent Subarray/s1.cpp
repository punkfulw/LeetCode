// OJ: https://leetcode.com/problems/longest-turbulent-subarray/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        helper(arr, 0, ans);
        helper(arr, 1, ans);
        return ans;
    }
    void helper(vector<int>& arr, int oe, int &ans){
        int cur = 1;
        for (int i = 0; i < arr.size()-1; i++){
            if ((i + oe) % 2){
                if (arr[i] > arr[i+1]){
                    cur++;
                    ans = max(ans, cur);
                }
                else
                    cur = 1;
            }
            else {
                if (arr[i] < arr[i+1]){
                    cur++;
                    ans = max(ans, cur);
                }
                else
                    cur = 1;
            }
        }
    }
};
