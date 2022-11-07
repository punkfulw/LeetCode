// OJ: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(N)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> str2sum;
        vector<string> ans;
        int least = INT_MAX, n = list1.size(), m = list2.size();
        
        for (int i = 0; i < n; ++i)
            str2sum[list1[i]] = -i;
        for (int i = 0; i < m; ++i){
            string s = list2[i];
            if (str2sum.find(s) != str2sum.end()){
                str2sum[s] = i - str2sum[s];
                least = min(least, str2sum[s]);
            }
        }

        for (auto &[s, sum]: str2sum)
            if (sum == least)
                ans.push_back(s);  
        return ans;
    }
};
