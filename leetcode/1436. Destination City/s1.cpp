// OJ: https://leetcode.com/problems/destination-city/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int size = paths.size();
        map<string, int> city ;
        string ans;
        
        for (int i = 0; i < size; i++){
            city[paths[i][0]]++;
            city[paths[i][1]]--;
        }
        
        for (auto i: city){
            if (i.second == -1)
                ans = i.first;
        } 
        return ans;
    }
};
