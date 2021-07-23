// OJ: https://leetcode.com/problems/beautiful-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/beautiful-array/discuss/186679/Odd-%2B-Even-Pattern-O(N)
// Time: O(NlogN)
// Space: O(NlogN)
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};
        
        while (ans.size() < n){
            vector<int>tmp;
            for (auto i: ans)
                if (2 * i - 1 <= n)
                    tmp.push_back(2 * i - 1);
            for (auto i: ans)
                if (2 * i <= n)
                    tmp.push_back(2 * i);
            ans = tmp;
        }
        return ans;
    }
};
