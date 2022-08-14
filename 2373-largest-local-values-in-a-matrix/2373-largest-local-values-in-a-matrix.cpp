class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> arr(n-2,vector<int>(n-2,0));
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=n-3;j++){
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        arr[i][j]=max(arr[i][j],grid[i+a][j+b]);
                    }
                }
            }
        }
        return arr;
    }
};