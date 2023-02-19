// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int x = 1;
        while(!q.empty()){
            int sz = q.size();
            int i = 0;
            vector<int> res;
            while(i < sz){
                auto curr = q.front();
                q.pop();
                res.push_back(curr-> val);
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                i++;
            }
            if(x) ans.push_back(res);
            else {
                reverse(res.begin(), res.end());
                ans.push_back(res);
            }
            x ^= 1;
        }
        return ans;
    }
};
