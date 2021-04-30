// OJ: https://leetcode.com/problems/build-an-array-with-stack-operations/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans {};
        int cnt {};
        
        for (int i = 0; i < target.size(); i++){
            if (target[i] == cnt + 1){
                ans.push_back("Push");
                cnt++;
            }
            else{
                while (target[i] != cnt + 1){
                    ans.push_back("Push");  
                    ans.push_back("Pop");
                    cnt++;
                }
                i--;
            }
        }
        return ans;
    }
};
