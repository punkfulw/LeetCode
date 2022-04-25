# [284. Peeking Iterator (Medium)](https://leetcode.com/problems/peeking-iterator/)

<p>Design an iterator that supports the <code>peek</code> operation on an existing iterator in addition to the <code>hasNext</code> and the <code>next</code> operations.</p>

<p>Implement the <code>PeekingIterator</code> class:</p>

<ul>
	<li><code>PeekingIterator(Iterator&lt;int&gt; nums)</code> Initializes the object with the given integer iterator <code>iterator</code>.</li>
	<li><code>int next()</code> Returns the next element in the array and moves the pointer to the next element.</li>
	<li><code>boolean hasNext()</code> Returns <code>true</code> if there are still elements in the array.</li>
	<li><code>int peek()</code> Returns the next element in the array <strong>without</strong> moving the pointer.</li>
</ul>

<p><strong>Note:</strong> Each language may have a different implementation of the constructor and <code>Iterator</code>, but they all support the <code>int next()</code> and <code>boolean hasNext()</code> functions.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
[[[1, 2, 3]], [], [], [], [], []]
<strong>Output</strong>
[null, 1, 2, 2, 3, false]

<strong>Explanation</strong>
PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [<u><strong>1</strong></u>,2,3]
peekingIterator.next();    // return 1, the pointer moves to the next element [1,<u><strong>2</strong></u>,3].
peekingIterator.peek();    // return 2, the pointer does not move [1,<u><strong>2</strong></u>,3].
peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,<u><strong>3</strong></u>]
peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
peekingIterator.hasNext(); // return False
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li>All the calls to <code>next</code> and <code>peek</code> are valid.</li>
	<li>At most <code>1000</code> calls will be made to <code>next</code>, <code>hasNext</code>, and <code>peek</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> How would you extend your design to be generic and work with all types, not just integer?

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Design](https://leetcode.com/tag/design/), [Iterator](https://leetcode.com/tag/iterator/)

**Similar Questions**:
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)
* [Flatten 2D Vector (Medium)](https://leetcode.com/problems/flatten-2d-vector/)
* [Zigzag Iterator (Medium)](https://leetcode.com/problems/zigzag-iterator/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/peeking-iterator/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/peeking-iterator/discuss/1055887/C%2B%2B-or-Iterators-or-Caching-or-0ms-Beats-100-or-Explanation
// Time: O(1)
// Space: O(1) 
class PeekingIterator : public Iterator {
    int nextval;
    bool hasnext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    hasnext = Iterator::hasNext();
        if (hasnext)
            nextval = Iterator::next();
	}
	
	int peek() {
        return nextval;
	}
	
	int next() {
        int cur = nextval;
	    hasnext = Iterator::hasNext();
        if (hasnext)
            nextval = Iterator::next();
        return cur;
	}
	
	bool hasNext() const {
	    return hasnext;
	}
};
```

## Solution 1. -py

```python3
# OJ: https://leetcode.com/problems/peeking-iterator/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/peeking-iterator/discuss/1055977/Python-3-Greedy-and-lazy-24ms
# Time: O(1)
# Space: O(1) 
class PeekingIterator:
    def __init__(self, iterator):
        self._iter = iterator
        self.val = None
        self.hasnext = False
        self.next()
        
    def peek(self):
        return self.val

    def next(self):
        cur = self.val
        self.hasnext = self._iter.hasNext()
        if self.hasnext:
            self.val = self._iter.next()
        return cur

    def hasNext(self):
        return self.hasnext
```
