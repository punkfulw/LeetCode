// OJ: https://leetcode.com/problems/minimum-absolute-difference/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int dif = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n-1; i++)
            dif = min(dif, arr[i+1] - arr[i]);
        
        vector<vector<int>> ans;
        for (int i = 0; i < n-1; i++){
            if (arr[i+1] - arr[i] == dif)
                ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
    }
};
