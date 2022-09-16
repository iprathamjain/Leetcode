class Solution {
public:
    vector<vector<int>>dp;
    int y, t;
    int f(int i, int x, vector<int>& nums, vector<int>& mul){
        
        if(x>=mul.size())
            return 0;
        // if(i>j)
        //     return 0;
        
        if(dp[i][x]!=1e9)
            return dp[i][x];

        int front = nums[i]*mul[x] + f(i+1,x+1,nums,mul);
        
        int back = nums[t-(x-i)-1]*mul[x] + f(i,x+1,nums,mul);
        
        return dp[i][x] = max(front, back);
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        y = mul.size();
        t = nums.size();
        dp.resize(1001,vector<int>(1001,1e9));
        return f(0,0,nums,mul);
    }
};