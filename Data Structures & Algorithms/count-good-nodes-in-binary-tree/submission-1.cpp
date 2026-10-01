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
    int count = 0;
    
    int dfs(TreeNode* root,int max1){
        if(!root)return 0;

        if(root->val >= max1){
            count++;
        }

        dfs(root->right,max(max1,root->val));
        dfs(root->left,max(max1,root->val));
        return 0;
    }

    int goodNodes(TreeNode* root) {
        dfs(root,-9999);
        return this->count;
    }
};
