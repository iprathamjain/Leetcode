class Solution {
public:
    int ans = 0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool isvalid(int i, int j, vector<vector<char>>& g){
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size() or g[i][j]=='0')
            return false;
        return true;
    }
    
    void dfs(int i, int j, vector<vector<char>>& g){
        g[i][j] = '0';
        
        for(int k=0;k<4;k++){
            if(isvalid(i+dx[k],j+dy[k],g))
                dfs(i+dx[k],j+dy[k],g);
        }
    }
    
    int numIslands(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='1'){
                    ans++;
                    dfs(i,j,g);
                }
            }
        }
        
        return ans;
    }
};