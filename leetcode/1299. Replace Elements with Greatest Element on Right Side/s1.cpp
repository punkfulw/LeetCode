// OJ: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int high = -1;
        
        for (int i = arr.size()-1; i >= 0; i--){
            int temp = arr[i];
            arr[i] = high;
            high = max(high, temp);
        }
        return arr;
    }
};
