# OJ: https://leetcode.com/problems/duplicate-emails/
# Author: github.com/punkfulw

SELECT Email FROM Person GROUP BY Email HAVING COUNT(*) > 1
