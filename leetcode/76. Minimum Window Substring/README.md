# [76. Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)

<p>Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window substring</strong> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window. If there is no such substring</em><em>, return the empty string </em><code>""</code><em>.</em></p>

<p>The testcases will be generated such that the answer is <strong>unique</strong>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ADOBECODEBANC", t = "ABC"
<strong>Output:</strong> "BANC"
<strong>Explanation:</strong> The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "a", t = "a"
<strong>Output:</strong> "a"
<strong>Explanation:</strong> The entire string s is the minimum window.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a", t = "aa"
<strong>Output:</strong> ""
<strong>Explanation:</strong> Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == s.length</code></li>
	<li><code>n == t.length</code></li>
	<li><code>1 &lt;= m, n&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Uber](https://leetcode.com/company/uber), [Apple](https://leetcode.com/company/apple), [Snapchat](https://leetcode.com/company/snapchat), [VMware](https://leetcode.com/company/vmware), [Microsoft](https://leetcode.com/company/microsoft), [Flipkart](https://leetcode.com/company/flipkart), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Substring with Concatenation of All Words (Hard)](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)
* [Smallest Range Covering Elements from K Lists (Hard)](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)
* [Minimum Window Subsequence (Hard)](https://leetcode.com/problems/minimum-window-subsequence/)

## Solution 1. Minimum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/punkfulw
// Time: O(N*C)
// Space: O(C) where C is the range of characters
class Solution {
public:
    string minWindow(string s, string t) {
        int mapS[128] = {}, mapT[128] = {};
        for (auto c: t) mapT[c]++;
        for (auto c: s) mapS[c]++;
        for (int i = 0; i < 128; i++)
            if (mapT[i] > mapS[i])
                return "";
        
        return check(mapT, s, t);
    }
    string check(int* mapT, string s, string t){
        int mapS[128] = {};
        int start = 0;
        string ans = s;
        for (int end = 0; end < s.size(); end++){
            mapS[s[end]]++;
            
            while (end-start+1 >= t.size() && cover(mapS, mapT)){
                mapS[s[start]]--;
                ans = ans.size() > end-start+1 ? s.substr(start, end-start+1) : ans;
                start++;
            }
        }
        return ans;
    }
    bool cover(int* mapS, int* mapT){
        for (int i = 0; i < 128; i++)
            if (mapT[i] > mapS[i])
                return false;
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/punkfulw
// Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
// Time: O(N)
// Space: O(C) where C is the range of characters
class Solution {
public:
    string minWindow(string s, string t) {
        int m[128] = {};
        for (char c : t) ++m[c];
        int begin = 0, end = 0, head = 0, cnt = t.size(), len = INT_MAX;
        while (end < s.size()) {
            if (--m[s[end++]] >= 0) --cnt;
            while (!cnt) {
                if (end - begin < len) len = end - (head = begin);
                if (++m[s[begin++]] > 0) ++cnt;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};
```
