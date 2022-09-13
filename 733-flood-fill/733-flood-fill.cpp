class Solution {
public:
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(int i, int j, vector<vector<int>>& image, int col, int ini){
        if(i<0 or j<0 or i>=image.size() or j>=image[0].size() or image[i][j]!=ini or image[i][j]==col)
            return ;
        
        image[i][j]=col;
        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],image,col,ini);
        }
    }
    //0 0 0
    //0 0 0
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        dfs(sr,sc,image,color,ini);
        return image;
    }
};