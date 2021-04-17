// OJ: https://leetcode.com/problems/count-items-matching-a-rule/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans {};
        int size = items.size();
        if (ruleKey == "type"){
            for (int i = 0; i < size; i++){
                if (items[i].at(0) == ruleValue){
                    ans++;
                }
            }
        }
        else if(ruleKey == "color"){
            for (int i = 0; i < size; i++){
                if (items[i].at(1) == ruleValue)
                    ans++;
            }
        }
        else if (ruleKey == "name"){
            for (int i = 0; i < size; i++){
                if (items[i].at(2) == ruleValue)
                    ans++;
            }
        }
        return ans;
    }
};
