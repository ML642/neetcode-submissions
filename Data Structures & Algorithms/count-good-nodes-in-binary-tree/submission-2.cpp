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
    
    int dfs(TreeNode* root,int max1){
        if(!root)return 0;
        int count = 0;

        if(root->val >= max1){
            count = 1;
        }

        int left = dfs(root->right,max(max1,root->val));
        int right = dfs(root->left,max(max1,root->val));
        return count+left+right;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};
