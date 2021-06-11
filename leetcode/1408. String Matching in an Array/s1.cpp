// OJ: https://leetcode.com/problems/string-matching-in-an-array/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (auto a: words){
            for (auto b: words){
                if (a != b && b.find(a) != -1){
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};
