# [2207. Maximize Number of Subsequences in a String (Medium)](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/)

<p>You are given a <strong>0-indexed</strong> string <code>text</code> and another <strong>0-indexed</strong> string <code>pattern</code> of length <code>2</code>, both of which consist of only lowercase English letters.</p>

<p>You can add <strong>either</strong> <code>pattern[0]</code> <strong>or</strong> <code>pattern[1]</code> anywhere in <code>text</code> <strong>exactly once</strong>. Note that the character can be added even at the beginning or at the end of <code>text</code>.</p>

<p>Return <em>the <strong>maximum</strong> number of times</em> <code>pattern</code> <em>can occur as a <strong>subsequence</strong> of the modified </em><code>text</code>.</p>

<p>A <b>subsequence</b> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "abdcdbc", pattern = "ac"
<strong>Output:</strong> 4
<strong>Explanation:</strong>
If we add pattern[0] = 'a' in between text[1] and text[2], we get "ab<u><strong>a</strong></u>dcdbc". Now, the number of times "ac" occurs as a subsequence is 4.
Some other strings which have 4 subsequences "ac" after adding a character to text are "<u><strong>a</strong></u>abdcdbc" and "abd<u><strong>a</strong></u>cdbc".
However, strings such as "abdc<u><strong>a</strong></u>dbc", "abd<u><strong>c</strong></u>cdbc", and "abdcdbc<u><strong>c</strong></u>", although obtainable, have only 3 subsequences "ac" and are thus suboptimal.
It can be shown that it is not possible to get more than 4 subsequences "ac" by adding only one character.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "aabb", pattern = "ab"
<strong>Output:</strong> 6
<strong>Explanation:</strong>
Some of the strings which can be obtained from text and have 6 subsequences "ab" are "<u><strong>a</strong></u>aabb", "aa<u><strong>a</strong></u>bb", and "aab<u><strong>b</strong></u>b".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pattern.length == 2</code></li>
	<li><code>text</code> and <code>pattern</code> consist only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Longest Common Subsequence (Medium)](https://leetcode.com/problems/longest-common-subsequence/)

## Solution 1. 

I first create two string, first one with a append at front and second one with b append at last.

and record the prefix of a in the first string and suffix of b in the second string.

```cpp
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
```


## Solution 2. Optimization


```cpp
// OJ: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/discuss/1863900/JavaC%2B%2BPython-Straight-Forward-Solution
// Time: O(N)
// Space: O(1)
long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0, cnt1 = 0, cnt2 = 0;
        for (char& c: text) {   
            if (c == pattern[1])
                res += cnt1, cnt2++;
            if (c == pattern[0])
                cnt1++;
        }
        return res + max(cnt1, cnt2);
    }
```

## Discuss

https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/discuss/1863963
