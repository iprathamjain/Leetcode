class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=n-1;i>=0;i--){
            vector<int>tmp;
            int a = i, b=0;
            while(a<n and b<m){
                tmp.push_back(mat[a][b]);
                a++;b++;
            }
            sort(tmp.begin(),tmp.end(),greater<int>());
            a=i;
            b=0;
            while(a<n and b<m){
                mat[a][b] = tmp.back();
                tmp.pop_back();
                a++;b++;
            }
        }
        
        
        for(int i=1;i<m;i++){
            vector<int>tmp;
            int a = 0, b=i;
            while(a<n and b<m){
                tmp.push_back(mat[a][b]);
                a++;b++;
            }
            sort(tmp.begin(),tmp.end(),greater<int>());
            a=0;
            b=i;
            while(a<n and b<m){
                mat[a][b] = tmp.back();
                tmp.pop_back();
                a++;b++;
            }
        }   
        
        return mat;
    }
};
