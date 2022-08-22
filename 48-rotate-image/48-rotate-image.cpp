//transpose then reverse each row.
class Solution {
public:
    void transpose(vector<vector<int>>&m){
        for(int i=0;i<m.size();i++){
            for(int j=i+1;j<m[0].size();j++){
                swap(m[i][j],m[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};