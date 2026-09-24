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
    vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode*> a;
       vector<vector<int>> b;
        if(!root) return b;
       a.push(root);
       while(!a.empty()){
     

            int level = a.size();
            vector<int> push_;
            for(int i=0;i<level;i++){
                TreeNode* node = a.front();
                a.pop();
                push_.push_back(node->val);
                if(node->left)a.push(node->left);
                if(node->right)a.push(node->right);
                
            }
            b.push_back(push_);
       } 
       return b;
    }
};
