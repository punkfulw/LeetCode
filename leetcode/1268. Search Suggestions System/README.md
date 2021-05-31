# [1268. Search Suggestions System (Medium)](https://leetcode.com/problems/search-suggestions-system/)

<p>Given an array of strings <code>products</code> and a string <code>searchWord</code>. We want to design a system that suggests at most three product names from <code>products</code>&nbsp;after each character of&nbsp;<code>searchWord</code> is typed. Suggested products should have common prefix with the searchWord. If there are&nbsp;more than three products with a common prefix&nbsp;return the three lexicographically minimums products.</p>

<p>Return <em>list of lists</em> of the suggested <code>products</code> after each character of&nbsp;<code>searchWord</code> is typed.&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
<strong>Output:</strong> [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
<strong>Explanation:</strong> products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> products = ["havana"], searchWord = "havana"
<strong>Output:</strong> [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
<strong>Output:</strong> [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> products = ["havana"], searchWord = "tatiana"
<strong>Output:</strong> [[],[],[],[],[],[],[]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= products.length &lt;= 1000</code></li>
	<li>There are no&nbsp;repeated elements in&nbsp;<code>products</code>.</li>
	<li><code>1 &lt;= Σ products[i].length &lt;= 2 * 10^4</code></li>
	<li>All characters of <code>products[i]</code> are lower-case English letters.</li>
	<li><code>1 &lt;= searchWord.length &lt;= 1000</code></li>
	<li>All characters of <code>searchWord</code>&nbsp;are lower-case English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/search-suggestions-system/
// Author: github.com/punkfulw
// Time: O(MlogM) 
// Space: O(N)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = searchWord.size();
        int m = products.size();
        vector<vector<string>> ans(n);
        sort(products.begin(), products.end());

        for (int i = 0; i < n; i++){
            string s = searchWord.substr(0, i+1);
            int n = 3;
            for (int j = 0; j < m; j++){
                if (products[j].substr(0,i+1) == s){
                    n--;
                    ans[i].push_back(products[j]);
                }
                if (n == 0)
                    break;
            }
        }
        return ans;
    }
};
```

## Solution 2. lower_bound

```cpp
// OJ: https://leetcode.com/problems/search-suggestions-system/
// Author: github.com/punkfulw
// Refernce: https://leetcode.com/problems/search-suggestions-system/discuss/436674/C%2B%2BJavaPython-Sort-and-Binary-Search-the-Prefix
// Time: O(NlogN) 
// Space: O(logN)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};
```
