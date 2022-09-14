class Solution {
public:
    int f(int ind, int tar, vector<int>& arr,vector<vector<int>>&dp){
        if(tar==0)
            return 0;
        if(tar<0)
            return 1e9;
        if(ind == 0){
            if(tar%arr[0]==0)
                return tar/arr[0];
            else 
                return 1e9;
        }
        if(dp[ind][tar]!=-1)
            return dp[ind][tar];
        int pick = 1e9;
        if(arr[ind]<=tar)
            pick = 1 + f(ind,tar-arr[ind],arr,dp);
        int notpick = f(ind - 1, tar, arr,dp);
        
        return dp[ind][tar] = min(pick,notpick);
            
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        if(amount == 0)
            return 0;
        
        int ans = f(n-1,amount,coins,dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};