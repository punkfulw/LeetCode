// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/546779/C%2B%2B-Brute-Force-or-Binary-Search
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        
        for (int i: arr1){
            if (upper_bound(arr2.begin(), arr2.end(), i+d) == lower_bound(arr2.begin(), arr2.end(), i-d))
                ans++;
        }
        return ans;
    }
};
