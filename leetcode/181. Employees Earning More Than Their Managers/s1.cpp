# OJ: https://leetcode.com/problems/employees-earning-more-than-their-managers/
# Author: github.com/punkfulw

SELECT e.Name AS Employee FROM Employee AS e, Employee AS m
WHERE e.ManagerId = m.Id AND e.Salary > m.Salary
