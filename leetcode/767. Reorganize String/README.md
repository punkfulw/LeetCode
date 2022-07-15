# [767. Reorganize String (Medium)](https://leetcode.com/problems/reorganize-string/)

<p>Given a string <code>S</code>, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.</p>

<p>If possible, output any possible result.&nbsp; If not possible, return the empty string.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> S = "aab"
<strong>Output:</strong> "aba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> S = "aaab"
<strong>Output:</strong> ""
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>S</code> will consist of lowercase letters and have length in range <code>[1, 500]</code>.</li>
</ul>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)
* [Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(A)
class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {}, most = 0;
        for (auto c: s)
            most = ++cnt[c - 'a'] > cnt[most] ? c - 'a' : most;
        if (cnt[most] * 2 - 1 > s.size())
            return "";
        int i = 0;
        for (; cnt[most]; i += 2, cnt[most]--)
            s[i] = most + 'a';
        
        for (int j = 0; j < 26; j++){
            while (cnt[j]--){
                if (i >= s.size())
                    i = 1;
                s[i] = j + 'a';
                i += 2;
            }
        }
        return s;
    }
};
```

## Solution 2. Greedy + Heap

```cpp
// OJ: https://leetcode.com/problems/reorganize-string/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for (auto c: s)
            mp[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto p: mp)
            pq.push({p.second, p.first});
        string ans = "";

        while (!pq.empty()){
            auto num1 = pq.top(); pq.pop();
            if (pq.empty()){
                if (num1.first > 1)
                    return "";
                else 
                    return ans + num1.second;
            }
            
            auto num2 = pq.top(); pq.pop();
            ans = ans + num1.second + num2.second;

            if (--num1.first)
                pq.push(num1);
            if (--num2.first)
                pq.push(num2);
        }
        return ans;
    }
};
```
