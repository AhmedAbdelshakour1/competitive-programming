// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        prev = root;
        root->left = NULL;
    }
};

// Appraoch -> O(1) space

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* tmp = curr->left;
                while(tmp->right != NULL) tmp = tmp->right;
                tmp->right = curr->right;
                curr->right = curr->left;
            } 
            curr->left = NULL;
            curr = curr->right;
        }
    }
};
