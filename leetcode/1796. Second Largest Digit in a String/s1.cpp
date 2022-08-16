// OJ: https://leetcode.com/problems/second-largest-digit-in-a-string
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int secondHighest(string s) {
        set<int> st;
        for (auto c: s)
            if (isdigit(c))
                st.insert(c - '0');
        int n = st.size();
        return n >= 2 ? *next(st.begin(), n - 2) : -1;
    }
};
