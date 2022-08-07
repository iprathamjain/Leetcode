class Solution {
public:
    vector<int>dp;
    bool f(int i,vector<int>& nums){
        if(i>=size(nums))
            return true;
        
        bool a=false,b=false,c=false;
        if(dp[i]!=-1)
            return dp[i];
        // for(int i=ind;i<size(nums);i++){
            if(i+1<size(nums) and nums[i]==nums[i+1])
                a = f(i+2,nums);
            if(i+2<size(nums) and nums[i]==nums[i+1] and nums[i+1]==nums[i+2])
                b = f(i+3,nums);
            if(i+2<size(nums) and nums[i+1]-nums[i]==1 and nums[i+2]-nums[i+1]==1)
                c =  f(i+3,nums);
        // }
        return dp[i] = (a or b or c);
    }
    bool validPartition(vector<int>& nums) {
        int n = size(nums);
        dp.resize(n+1,-1);
        return f(0,nums);
    }
};