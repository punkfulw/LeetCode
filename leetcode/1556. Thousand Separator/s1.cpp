// OJ: https://leetcode.com/problems/thousand-separator/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string thousandSeparator(int n) {
        string ans = to_string(n);
        for (int cnt = 0, i = ans.size() - 1; i >= 0; i--){
            cnt++;
            if (cnt && cnt % 3 == 0 && i != 0)
                ans.insert(ans.begin() + i, '.');
        }
        return ans;
    }
};
