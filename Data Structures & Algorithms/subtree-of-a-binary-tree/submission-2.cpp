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
    bool find(TreeNode* root,TreeNode* subRoot)
    {
        if(!root) return false;
        if(root->val==subRoot->val && thesametree(root,subRoot))return true;

        bool right = find(root->right,subRoot);
        bool left = find(root->left,subRoot);

        return right || left;
    }
    bool thesametree(TreeNode* root,TreeNode* subroot){
        if(!root && !subroot)return true;
        if(!root && subroot)return false;
        if(root && !subroot)return false;
        if(root->val != subroot->val)return false;

        bool right = thesametree(root->right,subroot->right) && thesametree(root->left,subroot->left);
        
        return right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return find(root,subRoot);
    }
};
