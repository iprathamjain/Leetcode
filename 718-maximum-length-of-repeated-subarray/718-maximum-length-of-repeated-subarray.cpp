
class Solution {
public:
    
    // same as lngest common substring (tabulation)
//     int findLength(vector<int>& s1, vector<int>& s2) {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
//         for(int i=0;i<=n;i++){
//             dp[i][0] = 0;
//         }
        
//         for(int i=0;i<=m;i++){
//             dp[0][i] = 0;
//         }
        
//         int ans = 0;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                  if(s1[i-1]==s2[j-1]){
//                      dp[i][j] = (1+dp[i-1][j-1]);
//                      ans = max(ans,dp[i][j]);
//                  }
//                 else
//                   dp[i][j] = 0;
//             }
//         }
        
//         return ans;   
//     }
    
    
    //memoization
    int ans = 0;
    int f(int i,int j, vector<int> &s1, vector<int> &s2,vector<vector<int>>&dp){
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        f(i-1,j,s1,s2,dp);
        f(i,j-1,s1,s2,dp);
        
        if(s1[i]==s2[j])
            dp[i][j]  = 1+f(i-1,j-1,s1,s2,dp);
        else
            dp[i][j] = 0;
        
        ans = max(dp[i][j],ans);
        return dp[i][j];
        
    }

    int findLength(vector<int>& text1, vector<int>& text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        f(n-1,m-1,text1,text2,dp);
        return ans;
    }
    
};