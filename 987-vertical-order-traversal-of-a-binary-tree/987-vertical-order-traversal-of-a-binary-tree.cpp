
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>level;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        level[0][0].insert(root->val);
        while(!q.empty()){
            auto curr = q.front();q.pop();
            auto node = curr.first;
            int l = curr.second.first;
            int h = curr.second.second;
            
            if(node->left){
                level[l-1][h+1].insert(node->left->val);
                q.push({node->left,{l-1,h+1}});
            }
            if(node->right){
                level[l+1][h+1].insert(node->right->val);
                q.push({node->right,{l+1,h+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto x:level){
            vector<int>t;
            for(auto y:x.second){
                for(auto z:y.second)
                    t.push_back(z);
            }
            ans.push_back(t);
        }
        
        return ans;
        
    }
};