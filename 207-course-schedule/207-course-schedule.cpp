class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<vector<int>> adj(n+1);
        vector<int> indeg(n,0);
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) que.push(i);
        }
        
        int cntr = 0;
        while(!que.empty()){
            int top = que.front();que.pop();
            cntr++;

            for(auto x:adj[top]){
                indeg[x]--;
                if(indeg[x]==0) que.push(x);
            }
        }
        
        if(cntr!=n)
            return false;
        return true;
    }
};