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
    bool valid(TreeNode* root,int lowerbound,int upperbound){
        if(!root){ 
            return true;
        }

        if(root->val <= lowerbound || root->val >= upperbound){
            return false;
        }

        return valid(root->right,root->val,upperbound) && valid(root->left,lowerbound,root->val);
    }


    bool isValidBST(TreeNode* root) {
        return valid(root,INT_MIN,INT_MAX);
    }
};
