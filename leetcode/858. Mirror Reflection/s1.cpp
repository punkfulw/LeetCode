// OJ: https://leetcode.com/problems/mirror-reflection/
// Author: github.com/punkfulw
// Time: O(P)
// Space: O(1)
class Solution {
public:
    int check(vector<vector<int>> &conner, vector<int> &start){
        int ans = -1;
        for (int i = 0; i < 3; i++)
            if (start == conner[i])
                ans = i;
        return ans;
    }
    int mirrorReflection(int p, int q) {
        int n = p, ans = -1, dir = 1;
        vector<vector<int>> conner = {{0, n}, {n, n}, {n, 0}};
        vector<int> start = {0, 0};

        while (ans == -1){
            start[1] = dir == 1 ? n : 0;
            if (start[0] + q > n || start[0] + q < 0){
                start[0] = start[0] + q > n ? n - (start[0] + q - n) : -(start[0] + q);
                q = -q;
            }
            else
                start[0] += q;

            dir = -dir;
            ans = check(conner, start);
        }
        return ans;
    }
};
