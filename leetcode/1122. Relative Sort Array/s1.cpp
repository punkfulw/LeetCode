// OJ: https://leetcode.com/problems/relative-sort-array/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(M)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        
        
        for (auto i: arr1){
            mp[i]++;
        }
        int index {};
        for (auto i: arr2){
            while (mp[i] > 0){
                arr1[index++] = i;
                mp[i]--;
            }
        }
        
        for (auto it: mp){
            while (it.second > 0){
                arr1[index++] = it.first;
                it.second--;
            }
        }
        return arr1;
    }
};
