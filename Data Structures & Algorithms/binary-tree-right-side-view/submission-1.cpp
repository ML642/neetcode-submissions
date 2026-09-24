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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> answer;
        if(!root)return answer;
        q.push(root);
        while(!q.empty()){  
            int level = q.size();
            bool flag = true;
            for(int i=0;i<level;i++){
                TreeNode* top = q.front();
                q.pop();
                if(flag){
                    answer.push_back(top->val);
                    flag = false;
                }
            

                if(top->right)q.push(top->right);
                if(top->left) q.push(top->left);
            }
        }
        return answer;
    }
};
