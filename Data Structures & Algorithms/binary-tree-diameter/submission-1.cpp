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
    int width = 0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int right = solve(root->right);
        int left = solve(root->left);

        this->width =max(right+left,this->width);
        return 1+max(right, left);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return this->width;
    }
};
