# [316. Remove Duplicate Letters (Medium)](https://leetcode.com/problems/remove-duplicate-letters/)

<p>Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <code>"bcabc"</code>
<b>Output:</b> <code>"abc"</code>
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> <code>"cbacdcbc"</code>
<b>Output:</b> <code>"acdb"</code>
</pre>

**Companies**:  
[Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. 


```cpp
// OJ: https://leetcode.com/problems/remove-duplicate-letters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mp[256];
        bool visited[256];
        string ans = "0";
        
        for (auto c: s)
            mp[c]++;
        
        for (auto c: s)
        {
            mp[c]--;
            if (visited[c])
                continue;
            while (ans.back() > c && mp[ans.back()] && !visited[c])
            {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans += c;
            visited[c] = true;
        }
        return ans.substr(1);
    }
};
```
