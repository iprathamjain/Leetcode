class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans(n);
        ans[0] = {1};
        if(n==1)
            return ans;
        ans[1] = {1,1};
        if(n==2)
            return ans;
        for(int i=3;i<=n;i++){
            ans[i-1].resize(i,1);
            ans[i-1][0]=1;
            ans[i-1][i-1]=1;
            for(int j=0;j<i-2;j++){
                ans[i-1][j+1] = ans[i-2][j] + ans[i-2][j+1];
            }
        }
        return ans;
        
    }
};
//1
//11
//1_1