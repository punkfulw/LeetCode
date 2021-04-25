// OJ: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
// Author: github.com/punkfulw
// Time: O(N) Where N is the vector size.
// Space: O(1)
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans {};
        
        for (int i = 0; i < startTime.size(); i++){
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ans++;
        }
       return ans;
    }
};
