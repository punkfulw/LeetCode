// OJ: https://leetcode.com/problems/gas-station/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(), ttl = 0;
        for (int i = 0; i < n; i++)
        {
            gas[i] -= cost[i];
            ttl += gas[i];
        }
        int running = 0, cnt = 0, ans = -1;
        for (int i = 0; i < 2 * n; i++)
        {
            int cur = i % n;
            if (running + gas[cur] < 0)
                running = cnt = 0;
            else
            {
                running += gas[cur];
                cnt++;
                if (cnt == n)
                {
                    ans = i - n + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
