// OJ: https://leetcode.com/problems/course-schedule-iii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(), time = 0;
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        priority_queue<int> used;
        for (auto c: courses){
            time += c[0];
            used.push(c[0]);
            while (time > c[1]){
                time -= used.top();
                used.pop();
            }
        }
        return used.size();
    }
};
