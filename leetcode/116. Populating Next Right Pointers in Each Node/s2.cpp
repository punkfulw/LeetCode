// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        Node* first = root;
        while (first && first->left){
            for (auto node = first; node; node = node->next){
                node->left->next = node->right;
                if (node->next)
                    node->right->next = node->next->left;
            }
            first = first->left;
        }
        return root;
    }
};
