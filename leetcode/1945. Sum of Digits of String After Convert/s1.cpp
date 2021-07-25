// OJ: https://leetcode.com/contest/weekly-contest-251/problems/sum-of-digits-of-string-after-convert/
// Author: github.com/punkfulw
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    int getLucky(string s, int k) {
        string t;
        vector<int> rec;
        for(auto c: s)
            rec.push_back(c-'a'+1);
        int ans = 0;
        for (auto i: rec){
            while (i > 0){
                ans += i % 10;
                    i /= 10;
            }
        }
        int res = ans;
        for (int i = 1; i < k; i++){
            res = 0;
            while (ans > 0){
                res += ans % 10;
                ans /= 10;
            }
            ans = res;
        }
        return res;
    }
};
