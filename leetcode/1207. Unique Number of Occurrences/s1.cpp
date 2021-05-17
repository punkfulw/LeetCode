// OJ: https://leetcode.com/problems/unique-number-of-occurrences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[2001] = {};
        
        for (int i: arr){
            cnt[i+1000]++;
        }
        int cmp[1001] = {};
            
        for (int i: cnt){
            if(cmp[i] == 0)
                cmp[i] = i;
            else
                return false;
        }
        return true;
    }
};
