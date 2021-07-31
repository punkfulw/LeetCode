# [677. Map Sum Pairs (Medium)](https://leetcode.com/problems/map-sum-pairs/)

<p>
Implement the <code>MapSum</code> class:
</p>

<ul>
  <li><code>MapSum()</code> Initializes the <code>MapSum</code> object.</li>
  <li><code>void insert(String key, int val)</code> Inserts the <code>key-val</code> pair into the map. 
    If the <code>key</code> already existed, the original <code>key-value</code> pair will be overridden to the new one.</li>
  <li><code>int sum(string prefix)</code> Returns the sum of all the pairs' value whose <code>key</code> starts with the <code>prefix</code>.</li>
</ul>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> ["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
<strong>Output:</strong> [null, null, 3, null, 5]
<strong>Explanation:</strong> 
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= key.length, prefix.length &lt;= 50</code></li>
  <li><code>key</code> and <code>prefix</code> consist of only lowercase English letters.</li>
  <li><code>1 &lt;= val &lt;= 1000</code></li>
  <li>At most <code>50</code> calls will be made to <code>insert</code> and <code>sum</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)



## Solution 1. map

```cpp
// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class MapSum {
public:
    unordered_map<string, int> map;
    MapSum() {}
    
    void insert(string key, int val) {
        map[key] = val;
    }
  
    int sum(string prefix) {
        int ans = 0;
        for (auto p: map){
            int n = p.first.size();
            int m = prefix.size();
            if (n < m)
                continue;
            if (p.first.substr(0, m) == prefix)
                ans += p.second;
        }
        return ans;
    }
};
```

## Solution 1. trie

```cpp
// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/map-sum-pairs/discuss/1371761/C%2B%2BPython-Trie-and-HashMap-Clean-and-Concise
// Ref: https://leetcode.com/problems/map-sum-pairs/discuss/107554/C%2B%2B-O(1)-9-lines-Trie-%2B-Hash-map
// Time: 
//       insert: O(K), where K <= 50 is length of key string.
//       sum: O(P), where P <= 50 is length of prefix string.
// Space: O(T), where T is the total of nodes after inserting all key string, T <= sum length of all key strings.
class MapSum {
    struct Trie{
        Trie* child[26] = {};
        int sum = 0;
    } root;
    unordered_map<string, int> map;
public:
    
    void insert(string key, int val) {
        int dif = val - map[key];
        auto p = &root;
        for (auto c: key){
            c -= 'a';
            if (p->child[c] == NULL)
                p->child[c] = new Trie;
            p = p->child[c] ;
            p->sum += dif;
        }
        map[key] = val;
    }
    
    int sum(string prefix) {
        auto p = &root;
        for (auto c: prefix){
            c -= 'a';
            if (p->child[c] == NULL)
                return 0;
            p = p->child[c];
        }
        return p->sum;
    }
};
```
