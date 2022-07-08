# [155. Min Stack (Easy)](https://leetcode.com/problems/min-stack/)

<p>Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.</p>

<p>Implement the <code>MinStack</code> class:</p>

<ul>
	<li><code>MinStack()</code> initializes the stack object.</li>
	<li><code>void push(int val)</code> pushes the element <code>val</code> onto the stack.</li>
	<li><code>void pop()</code> removes the element on the top of the stack.</li>
	<li><code>int top()</code> gets the top element of the stack.</li>
	<li><code>int getMin()</code> retrieves the minimum element in the stack.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

<strong>Output</strong>
[null,null,null,null,-3,null,0,-2]

<strong>Explanation</strong>
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Methods <code>pop</code>, <code>top</code> and <code>getMin</code> operations will always be called on <strong>non-empty</strong> stacks.</li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, and <code>getMin</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [VMware](https://leetcode.com/company/vmware), [Apple](https://leetcode.com/company/apple), [Yahoo](https://leetcode.com/company/yahoo), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Airtel](https://leetcode.com/company/airtel)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Max Stack (Easy)](https://leetcode.com/problems/max-stack/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/min-stack/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(N)
class MinStack {
public:
    vector<pair<int, int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        if (stk.empty())
            stk.push_back({val, val});
        else
            stk.push_back({val, min(stk.back().second, val)});
    }
    
    void pop() {
        stk.pop_back();
    }
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};
```
