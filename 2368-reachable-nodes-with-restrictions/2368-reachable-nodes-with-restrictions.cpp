class Solution {
public:
    int c = 0;
    vector<bool>vis;
    
    void dfs(int i,unordered_map<int,vector<int>>&adj,set<int>&res){
        if(vis[i])
            return;
        vis[i] = true;
        cout<<i<<" ";
        c++;
        
        for(auto it:adj[i]){
            if(res.find(it)==res.end())
                dfs(it,adj,res);            
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vis.resize(n+1,false);
        unordered_map<int,vector<int>>adj;
        set<int>res;
        for(auto x:restricted)
            res.insert(x);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,adj,res);
        return c;
        
        
    }
};