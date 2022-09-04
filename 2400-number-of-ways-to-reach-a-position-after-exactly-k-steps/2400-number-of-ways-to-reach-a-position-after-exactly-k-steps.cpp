class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>>dp;
    int f(int ind,int end, int k){
        if(ind == end and k==0)
            return 1;
        if((ind!=end and k==0) or k<0)
            return 0;
        if(dp[ind][k]!=-1)
            return (dp[ind][k])%mod;
        int left = f(ind-1,end,k-1);
        int right = f(ind+1,end,k-1);
        
        return dp[ind][k] = ((left)%mod+(right)%mod)%mod;
    }
    int numberOfWays(int st, int end, int k) {
        int i = st;
        int j = end;
        if(st-k<0){
            i+=+k;
            j+=k;
        }
        dp.resize(3001,vector<int>(3001,-1));
        return f(i,j,k)%mod;
    }
};