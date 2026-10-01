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
    int answer = 0 ;
    int dfs(TreeNode* root,int& k){
        if(!root) return -1;
        if(answer!=0) return -1; 

        dfs(root->left,k);
       
        k--;
        if(k==0 && answer==0 ){answer = root->val;}
        
        dfs(root->right,k);
        return -1;

    };


    int kthSmallest(TreeNode* root, int k) {
         dfs(root,k);
         return answer;
    }
};
