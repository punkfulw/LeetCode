# [182. Duplicate Emails (Easy)](https://leetcode.com/problems/duplicate-emails/)

<p>Write a SQL query to find all duplicate emails in a table named <code>Person</code>.</p>

<pre>+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
</pre>

<p>For example, your query should return the following for the above table:</p>

<pre>+---------+
| Email   |
+---------+
| a@b.com |
+---------+
</pre>

<p><strong>Note</strong>: All emails are in lowercase.</p>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/duplicate-emails/
# Author: github.com/punkfulw

SELECT Email FROM Person GROUP BY Email HAVING COUNT(*) > 1
```

