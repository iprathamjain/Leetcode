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
    int preindex = 0;
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int s, int e){
        if(s>e)
            return NULL;
        TreeNode* root = new TreeNode(pre[preindex++]);
        
        int inindex=0;
        for(int i=0;i<pre.size();i++){
            if(in[i]==root->val){
                inindex = i;
                break;
            }
        }
        
        root->left = build(pre,in,s,inindex-1);
        root->right = build(pre,in,inindex+1,e);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre,in,0,n-1);
    }
};