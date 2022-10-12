// OJ: https://leetcode.com/problems/linked-list-components/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Union_Find{
public:
    int parent[10001];
    
    Union_Find() {
        for (int i = 0; i < 10001; i++)
            parent[i] = i;
    }
    
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    void union_node(int a, int b){
        int pa = find(a), pb = find(b);
        if (pa < pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }
    
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        Union_Find uf;
        int pre = -1, cnt = 0, app[10001] = {};

        for (auto &i: nums)
            app[i] = 1;

        while (head){
            int cur = head->val;
            if (!app[cur])
                pre = -1;
            else {
                if (pre == -1)
                    pre = uf.find(cur);
                else
                    uf.union_node(pre, cur);
            }
            head = head->next;
            cnt++;
        }
        
        int ans = 0;
        for (int i = 0; i < cnt; i++)
            if (app[i] && uf.parent[i] == i)
                ans++;
        return ans;
    }
};
