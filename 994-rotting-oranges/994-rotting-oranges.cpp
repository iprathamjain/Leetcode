//MULTISOURCE BFS
class Solution {
public:
    int ans =0;
    queue<pair<int,int>>q;
    int ax[4] = {1,-1,0,0};
    int ay[4] = {0,0,1,-1};
    bool flag = false;
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();    
        // bool flag = false;
    
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        
        bfs(grid);

        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        if(q.empty() and flag == false)
            return 0;
        ans--;
        
        return ans;
        
    }
    
    bool isvalid(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();    
        return (x>=0 and y>=0 and x<n and y<m and grid[x][y]==1);
    }
    
    void bfs(vector<vector<int>>& grid){
        while(!q.empty()){
            flag = true;
            ans++;
            int s = q.size();
            while(s--){
                auto curr = q.front();q.pop();
                int i = curr.first;
                int j = curr.second;
                
                for(int k=0;k<4;k++){
                    if(isvalid(i+ax[k],j+ay[k],grid)){
                        q.push({i+ax[k],j+ay[k]});
                        grid[i+ax[k]][j+ay[k]] = 2;
                    }
                }
            }
        }
    }
};