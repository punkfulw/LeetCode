# [692. Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)

<p>Given an array of strings <code>words</code> and an integer <code>k</code>, return the <code>k</code> most frequent strings.</p>

<p>Return the answer <b>sorted</b> by <b>the frequency</b> from highest to lowest. Sort the words with the same frequency by their <b>lexicographical order</b>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> words = ["i","love","leetcode","i","love","coding"], k = 2
<strong>Output:</strong> ["i","love"]
<strong>Explanation:</strong> "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
<strong>Output:</strong> ["the","is","sunny","day"]
<strong>Explanation:</strong> "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= words.length &lt;= 500</code></li>
  <li><code>1 &lt;= words[i] &lt;= 10</code></li>
  <li><code>words[i]</code> consists of lowercase English letters.</li>
  <li><code>k</code> is in the range <code>[1, The number of unique words[i]]</code></li>
</ul>



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/top-k-frequent-words/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/top-k-frequent-words/discuss/108366/O(nlog(k))-Priority-Queue-C%2B%2B-code
// Time: O(Nlog(k))
// Space: O(N)
class Solution {
public:
    bool operator()(pair<string, int> a, pair<string, int> b){
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (auto word: words)
            mp[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Solution> pq;
        
        for(auto &p : mp) 
            pq.push(p);
        
        vector<string> ans;
        while(pq.size() && k--){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};
```
