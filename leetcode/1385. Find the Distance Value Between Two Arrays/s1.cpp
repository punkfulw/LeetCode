// OJ: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        
        for (int i: arr1){
            bool toadd = true;
            for (int j: arr2){
                if (abs(i-j) <= d){
                    toadd = false; 
                    break;
                }
            }
            if(toadd)
                ans++;
        }
        return ans;
    }
};
