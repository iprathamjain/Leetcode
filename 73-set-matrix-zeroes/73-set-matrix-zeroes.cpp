class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool row[n];
        bool col[m];
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(row[i])
                for(int j=0;j<m;j++){
                    mat[i][j] = 0;
                }
        }
        
        for(int i=0;i<m;i++){
            if(col[i])
                for(int j=0;j<n;j++){
                    mat[j][i] = 0;
                }
        }
        
        return ;
    }
};
