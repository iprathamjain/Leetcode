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
    void level(TreeNode* root, vector<vector<int>>& ans){
        if(root == NULL)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int c = q.size();
            vector<int>tp;
            for(int i =0;i<c;i++){
                TreeNode* tmp = q.front();
                q.pop();
                tp.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            ans.push_back(tp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        level(root,ans);
        return ans;
    }
};