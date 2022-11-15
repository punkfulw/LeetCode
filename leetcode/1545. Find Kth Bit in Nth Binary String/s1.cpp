// OJ: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    void invert(string &s){
        for (auto &c: s)
            c = c == '0' ? '1' : '0';
    }
    void sol(string &s, int k){
        if (s.size() >= k)
            return;
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        invert(tmp);
        s = s + "1" + tmp;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        while (s.size() < k)
            sol(s, k);
        return s[k - 1];
    }
};
