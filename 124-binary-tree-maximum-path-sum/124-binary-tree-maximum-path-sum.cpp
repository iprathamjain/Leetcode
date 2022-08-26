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
    int help(TreeNode* root,int &res){
        if(root==NULL)
            return 0;
        int lh = help(root->left,res);
        int rh = help(root->right,res);
        
        int tmp = max(max(lh,rh)+root->val,root->val);
        int ans = max(tmp,lh+rh+root->val);
        res = max(res,ans);
        return tmp;

    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int s = help(root,maxi);
        return maxi;
    }
};