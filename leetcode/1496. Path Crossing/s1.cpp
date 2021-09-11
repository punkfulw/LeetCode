// OJ: https://leetcode.com/problems/path-crossing/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        set<pair<int, int>> visited = {{i, j}};
        for (auto c: path){
            if (c == 'N') i += 1;
            else if (c == 'S') i -= 1;
            else if (c == 'E') j += 1;
            else j -= 1;
            if (visited.find({i, j}) != visited.end())
                return true;
            else
                visited.insert({i, j});
        }
        return false;
    }
};
