// https://leetcode.com/problems/find-duplicate-subtrees/description/

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
    unordered_map<string, int> mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        calc(root, ans);
        return ans;

    }
    string calc(TreeNode* root, vector<TreeNode*> &ans){
        if(root == NULL) return "";
        string left = calc(root -> left, ans);
        string right = calc(root -> right, ans);
        string curr = to_string(root -> val) + "$" + left + "$" + right;
        if(++mp[curr] == 2) ans.push_back(root);
        return curr;
    }
};
