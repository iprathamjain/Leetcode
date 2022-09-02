class Solution {
public:
    //Memoization code (o(n^2))
//     int f(int ind, int prevind, vector<int>& nums, vector<vector<int>>&dp){
//         if(ind == size(nums))
//             return 0;
//         if(dp[ind][prevind+1]!=-1)
//             return dp[ind][prevind+1];
//         int nottake = 0 + f(ind+1,prevind,nums,dp);
//         int take = 0;
//         if(prevind == -1 or nums[ind]>nums[prevind])
//             take = 1 + f(ind+1, ind, nums,dp);
//         return dp[i nd][prevind+1] = max(take,nottake);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = size(nums);
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return f(0,-1,nums,dp);
//     }
    //Tabulation code: (o(n^2))
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = size(nums);
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int ind = n-1;ind>=0;ind--){
//             for(int prevind = ind-1;prevind>=-1;prevind--){
//                 int nottake = 0 + dp[ind+1][prevind+1];
//                 int take = 0;
//                 if(prevind == -1 or nums[ind]>nums[prevind])
//                     take = 1 + dp[ind+1][ind+1];
//                 dp[ind][prevind+1] = max(take,nottake);
//             }
//         }
//         return dp[0][-1+1];
//     }
    
    //  int lengthOfLIS(vector<int>& nums) {
    //     int ans = 1, n = size(nums);
    //     vector<int> dp(n, 1);
    //     for(int i = 0; i < n; i++) 
    //         for(int j = 0; j < i; j++) 
    //             if(nums[i] > nums[j]) 
    // dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
    //     return ans;
    // }
    
    //BINARY SEARCH (0(NLOGN)) METHOD
    int lengthOfLIS(vector<int>& nums) {
       vector<int>temp;
        int len = 1;
        temp.push_back(nums[0]);
        for(int i=1;i<size(nums);i++){
            if(nums[i]>temp.back())
                temp.push_back(nums[i]),len++;                
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};
