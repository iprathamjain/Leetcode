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
    int ans = 0;
    void pre(TreeNode* root, int x){
        if(root==NULL){
            return;
        }
        if(root->val>=x)
            x = root->val,ans++;
        pre(root->left,x);
        pre(root->right,x);
    }
    
    int goodNodes(TreeNode* root) {
        pre(root,INT_MIN);
        return ans;
    }
};