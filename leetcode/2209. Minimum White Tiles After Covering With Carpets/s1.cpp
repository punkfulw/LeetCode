// OJ: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
// Author: github.com/punkfulw
// Time: O(N * C) floor * number of carpets
// Space: O(N * C)
class Solution {
public:
    int minimumWhiteTiles(string f, int numC, int cL) {
        
        int white = 0;
        for (auto c: f)
            if (c == '1')
                white++;
        
        if (f.size() <= numC * cL)
            return 0;

        while (numC-- && white > 0)
        {
            int cur = 0, start, end, zone = 0;
            zone = 0;
            for (int i = 0; i < f.size(); i++)
            {
                if (f[i] == '1')
                    cur++;
                if (i >= cL - 1)
                {
                    if (cur > zone)
                    {
                        zone = cur;
                        start = i - cL + 1;
                        end = i;
                    }
                }
                if (i >= cL - 1 && f[i - cL + 1] == '1')
                    cur--;
            }
            for (int i = start; i <= end; i++)
                f[i] = '0';
            white -= zone;
        }
        return max(white, 0);
    }
};
