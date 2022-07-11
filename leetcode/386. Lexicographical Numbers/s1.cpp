// OJ: https://leetcode.com/problems/lexicographical-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int i = 1;
        while (ans.size() < n){
            ans.push_back(i);
            if (i * 10 <= n)
                i *= 10;
            else {
                if (i % 10 == 9 || i + 1 > n){
                    i /= 10;
                    while (i % 10 == 9)
                        i /= 10;
                }
                i++;
            }
        }
        return ans;
    }
};
