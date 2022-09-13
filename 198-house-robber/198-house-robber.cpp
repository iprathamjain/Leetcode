class Solution {
public:
       int solve(vector<int>& nums, int n,vector<int>&dp){
        if(n>=nums.size())
            return 0;
        if(n==nums.size()-1)
            return nums[nums.size()-1];
        if(dp[n]!=-1)
            return dp[n];
        
        int inc = solve(nums,n+2,dp) + nums[n];
        int exc = solve(nums,n+1,dp) + 0;
        
        return dp[n] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int ans = solve(nums,0,dp);
        return ans;
    }
};