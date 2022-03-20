// OJ: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long maximumSubsequenceCount(string text, string p) {
        string text1 = p.substr(0, 1) + text, text2 = text;
        text2.push_back(p[1]);
        
        int n = text1.size();
        vector<int> b(n), a(n);
        long long ans = 0;
        
        a[0] = 1;
        b[n-1] = 1;
        
        for (int i = 1; i < n ; i++)
        {
            if (text1[i] == p[0])
                a[i] = a[i-1] + 1;
            else
                a[i] = a[i-1];
        }
        
        for (int i = n - 2; i >= 0 ; i--)
        {
            if (text2[i] == p[1])
                b[i] = b[i+1] + 1;
            else
                b[i] = b[i+1];
        }
         
        long long f1 = 0, f2 = 0;
    
        
        for (int i = 0; i < n; i++)
        {
            if (text1[i] == p[0])
                f1 += b[i] - 1;
            if (text2[i] == p[1])
                f2 += a[i] - 1;
        }
        
        return max(f1, f2);    
    }
};
