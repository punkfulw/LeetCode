// OJ: https://leetcode.com/problems/smallest-string-with-swaps/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/smallest-string-with-swaps/discuss/388257/C%2B%2B-with-picture-union-find
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int ufind(vector<int> &par, int i)
    {
        return par[i] < 0 ? i : par[i] = ufind(par, par[i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> par (n, -1);
        vector<vector<int>> arr(n);
        
        for (auto p: pairs)
        {
            int x = ufind(par, p[0]), y = ufind(par, p[1]);
            if (x != y)
            {
                if (par[x] < par[y])
                    swap(x, y);
                par[x] += par[y];
                par[y] = x;
            }
        }
        for (int i = 0; i < n; i++)
            arr[ufind(par, i)].push_back(i);
        
        for (auto ids: arr)
        {
            string ss = "";
            for (auto id: ids)
                ss += s[id];
            sort(ss.begin(), ss.end());
            for (int i = 0; i < ids.size(); i++)
                s[ids[i]] = ss[i];
        }
        return s;
    }
};
