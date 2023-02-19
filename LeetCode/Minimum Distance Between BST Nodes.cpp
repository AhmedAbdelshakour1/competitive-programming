// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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
    int minDistance = INT_MAX;
    TreeNode* prevValue;
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        
        inorderTraversal(root->left);
        if (prevValue != NULL) {
            minDistance = min(minDistance, root->val - prevValue->val);
        }
        prevValue = root;
        
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        return minDistance;
    }
};

// Another solution
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int> &ans) {
        if (root == NULL) return;
        inorderTraversal(root->left, ans);
        ans.push_back(root-> val);
        inorderTraversal(root->right, ans);
    }
    
    int minDiffInBST(TreeNode* root) {
        int minDistance = INT_MAX;
        vector<int> ans;
        inorderTraversal(root, ans);
        for(int i = 1; i < ans.size(); i++) minDistance = min(minDistance, ans[i] - ans[i - 1]);
        return minDistance;
    }
};
