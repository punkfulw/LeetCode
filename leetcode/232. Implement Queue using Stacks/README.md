# [232. Implement Queue using Stacks (Easy)](https://leetcode.com/problems/implement-queue-using-stacks/)

<p>Implement a first in first out (FIFO) queue using only two stacks. 
  The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).</p>

<p>Implement the MyQueue class:</p>

<ul>
	<li>void push(int x) Pushes element x to the back of the queue.</li>
	<li>int pop() Removes the element from the front of the queue and returns it.</li>
	<li>int peek() Returns the element at the front of the queue.</li>
	<li>boolean empty() Returns true if the queue is empty, false otherwise.</li>
</ul>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> ["MyQueue", "push", "push", "peek", "pop", "empty"]
<strong>Output:</strong> [null, null, null, 1, 1, false]
<strong>Explanation:</strong> 
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= x &lt;= 9</code></li>
  <li><code>At most 100 calls will be made to push, pop, peek, and empty.</code></li>
  <li><code>All the calls to pop and peek are valid.</code></li>
</ul>



**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Implement Stack using Queues (Easy)](https://leetcode.com/problems/implement-stack-using-queues/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-queue-using-stacks
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1)
class MyQueue {
public:
    stack<int> InStack, OutStack;
    MyQueue() {}

    void push(int x) {
        InStack.push(x);
    }

    int pop() {
        auto x = peek();
        OutStack.pop();
        return x;
    }

    int peek() {
        if (OutStack.empty()){  
            while (!InStack.empty()){
                auto x = InStack.top();
                InStack.pop();
                OutStack.push(x);
            }
        }
        return OutStack.top();
    }

    bool empty() {
        return InStack.empty() && OutStack.empty();
    }
};
```
