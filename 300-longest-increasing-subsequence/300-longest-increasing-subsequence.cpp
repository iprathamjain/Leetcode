class Solution {
public:
    
    int f(int ind, int prevind, vector<int>& nums,vector<vector<int>>&dp){
        if(ind == nums.size())
            return 0;
        if(dp[ind][prevind+1]!=-1)
            return dp[ind][prevind+1];
            
        int take = 0;
        if(prevind==-1 or nums[ind]>nums[prevind])
            take = 1 + f(ind+1,ind,nums,dp);
        int nottake = f(ind+1,prevind,nums,dp);
        
        return dp[ind][prevind+1] = max(take,nottake);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};