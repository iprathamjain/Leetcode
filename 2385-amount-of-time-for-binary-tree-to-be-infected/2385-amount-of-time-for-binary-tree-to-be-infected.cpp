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
    map<int,vector<int>>adj;
    
    
    int amountOfTime(TreeNode* root, int start) {
        build(root);
        // for(auto x:adj){
        //     cout<<x.first<<"    ";
        //     for(auto t:x.second){
        //         cout<<t<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<bool>vis(100001,false);
        queue<int>q;
        q.push(start);
        vis[start] = true;
        int ans = 0;
        while(!q.empty()){
            ans++;
            int s = q.size();
            while(s--){
                int a = q.front();
                q.pop();
                vis[a] = true;
                for(auto x:adj[a])
                {
                    if(!vis[x])
                        q.push(x);
                }
            }
            
        }
        
        if(ans==0)
            return 0;
        return ans-1;
        
            
    }
    void build(TreeNode* root){
        if(root == NULL or (root->left==NULL and root->right==NULL))
            return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        build(root->left);
        build(root->right);
    }
};