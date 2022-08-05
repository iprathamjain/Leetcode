class Solution {
public:
    
    int f(int ind,vector<int>& nums, int target,vector<vector<int>>&dp){
        if(ind==nums.size())
            return (target == 0);
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int take = f(0,nums,target-nums[ind],dp);
        int nottake = f(ind+1,nums,target,dp);
        return dp[ind][target] = take + nottake;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1001,-1));
        return f(0,nums,target,dp);
    }
};