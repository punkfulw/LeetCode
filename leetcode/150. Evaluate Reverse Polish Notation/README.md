# [150. Evaluate Reverse Polish Notation (Medium)](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

<p>Evaluate the value of an arithmetic expression in Reverse Polish Notation.</p>

<p>Valid operators are <code>+</code>, <code>-</code>, <code>*</code>, and <code>/</code>. Each operand may be an integer or another expression.</p>

<p><b>Note</b> that division between two integers should truncate toward zero.</p>

<p>It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> tokens = ["2","1","+","3","*"]
<strong>Output:</strong> 9
<strong>Explanation: </strong> ((2 + 1) * 3) = 9
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> tokens = ["4","13","5","/","+"]
<strong>Output:</strong> 6
<strong>Explanation: </strong> (4 + (13 / 5)) = 6
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
<strong>Output:</strong> 22
<strong>Explanation: </strong> ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
</pre>


tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200]

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= tokens.length &lt;= 10<sup>4</sup></code></li>
  <li><code>tokens[i]</code> is either an operator: <code>"+"</code>, <code>"-"</code>, <code>"*"</code>, or <code>"/"</code>, or an integer in the range <code>[-200, 200]</code></li>
</ul>



**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (auto t: tokens){
            if (isdigit(t[t.size()-1]))
                stk.push(stoi(t));
            else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch (t[0]){
                    case '+': stk.push(a+b); break;
                    case '-': stk.push(a-b); break;
                    case '*': stk.push(a*b); break;
                    case '/': stk.push(a/b); break;
                }
            }
        }
        return stk.top();
    }
};
```

